import { Box, Typography, createTheme, ThemeProvider, CssBaseline, TableFooter, TableRow, TableCell, Link } from '@mui/material'
import './App.css'
import { useState } from 'react'

import Input from './Components/Input.jsx'
import ChartMethod from './Components/ChartMehod.jsx'
import ChartComparation from './Components/ChartComparation.jsx'
import TextTerminal from './Components/TextTerminal.jsx'
import LinkGh from './Components/LinkGH.jsx'

function App() {
  const [simulationData, setSimulationData] = useState(null);

  const darkTheme = createTheme({
    palette: {
      mode: 'dark',
      background: {
        default: '#121212',
        paper: '#1e1e1e',
      },
    }
  })

  const handleSimulationComplete = (newData) => {
    setSimulationData(newData);
  };

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
          margin: '0 auto',
        }}>
          <Box className="input">
            <Input onSimulationComplete={handleSimulationComplete}/>
          </Box>

          {simulationData && simulationData.length > 0 && (
            <>
              <Typography variant="h2" gutterBottom>
                Métodos de Escalonamento
              </Typography>
              
              <Box 
                className="charts" 
                sx={{ 
                  display: 'flex', 
                  flexWrap: 'wrap', 
                  gap: '2rem', 
                  justifyContent: 'center' 
                }}
              >
                {simulationData.map((methodData, index) => (
                  <Box 
                    key={index}
                    sx={{
                      width: 'calc(50% - 1rem)', 
                      display: 'flex',
                      justifyContent: 'center'
                    }}
                  >
                    <ChartMethod data={methodData} />
                  </Box>
                ))}
              </Box>

              <Typography variant="h2" gutterBottom>
                Comparativo entre os métodos
              </Typography>
              <Box className="charts">
                <ChartComparation methods={simulationData} />
              </Box>
            </>
          )}
        </Box>
      </Box>
      <TableFooter>
        <TableRow>
          <TableCell colSpan={5} align="center" sx={{display: 'flex', gap: '1rem', alignItems: 'baseline', borderBottom: 'none', justifyContent: 'center'}}>
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