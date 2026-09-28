import { StrictMode } from 'react'
import { createRoot } from 'react-dom/client'
import App from './App.jsx'
import Container from '@mui/material/Container'

createRoot(document.getElementById('root')).render(
  <StrictMode>
    <Container maxWidth="lg">
      <App />
    </Container>
  </StrictMode>,
)
