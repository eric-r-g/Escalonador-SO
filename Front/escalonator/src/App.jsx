import {Box, Typography, createTheme,ThemeProvider, CssBaseline, TableFooter, TableRow, TableCell, Link} from '@mui/material'

import './App.css'
import Input from './Components/Input.jsx'
import data from './example.json'
import ChartMethod from './Components/ChartMehod.jsx'
import ChartComparation from './Components/ChartComparation.jsx'
import TextTerminal from './Components/TextTerminal.jsx'
import LinkGh from './Components/LinkGH.jsx'

function App() {
  const darkTheme = createTheme({
    palette: {
      mode: 'dark',
      background: {
        default: '#121212',
        paper: '#1e1e1e',
      },
    }
  })


  return (
    <ThemeProvider theme={darkTheme}>
      <CssBaseline/>
      <Box>
        <Box sx={{ textAlign: 'center', marginBottom: '2rem', marginTop: '2rem' }}>
          <TextTerminal variant="h2" text="Escalonador-de-Processos" />
        </Box>
        <Box sx={{ 
          display: 'flex', 
          flexDirection: 'column', 
          gap: '2rem', 
          width: '100%', 
          maxWidth: '1200px',
          marginBottom: '2rem',
        }}>
          <Box className="input">
            <Input/>
          </Box>
          <Typography variant="h2" gutterBottom>
            Métodos de Escalonamento
          </Typography>
          <Box className="charts" sx={{ display: 'flex', gap: '2rem' }}>
            <ChartMethod data={data[0]} />
            <ChartMethod data={data[1]} />
          </Box>
          <Box className="charts" sx={{ display: 'flex', gap: '2rem' }}>
            <ChartMethod data={data[2]} />
            <ChartMethod data={data[3]} />
          </Box>
          <Box className="charts" sx={{ display: 'flex', gap: '2rem' }}>
            <ChartMethod data={data[4]} />
            <ChartMethod data={data[5]} />
          </Box>
          <Box className="charts" sx={{ display: 'flex', gap: '2rem', justifyContent: 'center' }}>
            <ChartMethod data={data[6]} />
          </Box>
          <Typography variant="h2" gutterBottom>
            Comparativo entre os métodos
          </Typography>
          <Box className="charts" >
            <ChartComparation methods={data} />
          </Box>
        </Box>
      </Box>
      <TableFooter>
          <TableRow>
          <TableCell colSpan={5} align="center" sx={{display: 'flex', gap: '1rem', alignItems: 'baseline', borderBottom: 'none' }}>
            <LinkGh nome="João Gabriel" link="https://github.com/JGabrielRS"/>
            <LinkGh nome="Guilherme Gondim" link="https://github.com/guilhermeglga"/>
            <LinkGh nome="Eric Rodrigues" link="https://github.com/eric-r-g"/>
          </TableCell>
        </TableRow>
      </TableFooter>
    </ThemeProvider>
  )
}

export default App