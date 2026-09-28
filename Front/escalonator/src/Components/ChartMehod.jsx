import { Card, CardContent, CardMedia, CardHeader, Box, Typography, Divider } from '@mui/material'
import Chart from './Chart.jsx'

function ChartMethod({ data }) {

    return (
        <>
            <Card sx={{ border: '2px solid #1e1e1e', height: '100%', display: 'flex', flexDirection: 'column' }}>
              <CardHeader title={`Gráfico de ${data.id}`}  sx={{backgroundColor: "#121212"}}/>
              <CardMedia>
                <Chart data={data} />
              </CardMedia>
              <CardContent sx={{ flexGrow: 1 }}>
                <Box sx={{ display: 'flex', justifyContent: 'space-between', alignItems: 'center', gap: '1rem', marginTop: '1rem', textAlign: 'center' }}>
                  <Box sx={{ flex: 1 }}>
                    <Typography variant="h6">Tempo médio de vida</Typography>
                    <Typography variant="h4"><Typography variant="h8">{data.tt}</Typography>s</Typography>
                  </Box>
                  <Divider orientation="vertical" flexItem sx={{ borderRightWidth: 2, borderColor: '#f0f0f0' }} />
                  <Box sx={{ flex: 1 }}>
                    <Typography variant="h6">Tempo médio de espera</Typography>
                    <Typography variant="h4"><Typography variant="h8">{data.tw}</Typography>s</Typography>
                  </Box>
                  <Divider orientation="vertical" flexItem sx={{ borderRightWidth: 2, borderColor: '#f0f0f0' }} />
                  <Box sx={{ flex: 1 }}>
                    <Typography variant="h6">Troca de Contextos</Typography>
                    <Typography variant="h4"><Typography variant="h8">{data.num_trocas}</Typography></Typography>
                  </Box>
                </Box>
              </CardContent>
            </Card>
        </>
    )
}

export default ChartMethod