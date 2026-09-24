import {Box, Typography, TextField} from '@mui/material'
import './App.css'
import Input from './Components/Input.jsx'
import data from './example.json'
import Chart from './Components/Chart.jsx'

function App() {

  return (
    <Box>
      <Box sx={{ textAlign: 'center', marginBottom: '2rem', marginTop: '2rem' }}>
        <Typography variant="h2" gutterBottom>
          Trabalho de Sistemas Operacionais - Escalonador de Processos
        </Typography>
      </Box>
      <Box sx={{ 
        display: 'flex', 
        flexDirection: 'column', 
        gap: '2rem', 
        width: '100%', 
        maxWidth: '1200px'
      }}>
        <Box className="input">
          <Input/>
        </Box>
        <Box className="charts">
          <Chart data={data} />
        </Box>
      </Box>
    </Box>
  )
}

export default App