import { Link } from '@mui/material';
import GitHubIcon from '@mui/icons-material/GitHub';

function LinkGh({nome, link}) {

    return (
        <Link 
        href={link} 
        underline="hover" 
        color="inherit" 
        variant="body1"
        sx={{
        display: 'inline-flex',
        alignItems: 'center',
        
        '& .MuiSvgIcon-root': {
          maxWidth: 0, 
          opacity: 0, 
          transform: 'translateY(10px)', 
          marginRight: 0, 
          transition: 'all 0.3s ease-out', 
        },
        
        '&:hover .MuiSvgIcon-root': {   
          maxWidth: '24px',
          opacity: 1,
          transform: 'translateY(-4px)',
          marginRight: '0.4rem',
        },
        }}
        >
            <GitHubIcon sx={{ fontSize: '1.2rem', color: 'white' }} />
            {nome}
        </Link>
    )
}

export default LinkGh;