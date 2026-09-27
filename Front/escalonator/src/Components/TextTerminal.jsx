import { Typography } from '@mui/material';

function TextTerminal({ variant, text }) {
    return (
        <Typography 
            variant={variant}
            sx={{
              fontFamily: '"Fira Code", "Courier New", monospace', 
              color: '#ffffff',
              fontWeight: 'bold',
              display: 'inline-block',
              overflow: 'hidden',
              whiteSpace: 'nowrap',
              borderRight: '4px solid #ffffff',
              paddingRight: '4px',
              animation: 'typing 3.5s steps(50, end), blink-caret 0.75s step-end infinite',
              
              '@keyframes typing': {
                from: { maxWidth: '0%' },
                to: { maxWidth: '100%' },
              },
              '@keyframes blink-caret': {
                'from, to': { borderColor: 'transparent' },
                '50%': { borderColor: '#ffffff' },
              }
            }}
          >
            {text}
          </Typography>
    )
}

export default TextTerminal