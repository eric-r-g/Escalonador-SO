import { Bar } from 'react-chartjs-2'

import {
  Chart as ChartJS,
  CategoryScale,
  LinearScale,
  BarElement,
  Tooltip,
  Legend,
} from 'chart.js'

import { Card, CardHeader, CardMedia } from '@mui/material'

ChartJS.register(
  CategoryScale,
  LinearScale,
  BarElement,
  Tooltip,
  Legend
)

function ChartComparation({ methods }) {
  const labels = methods.map((method) => method.id)

  const comparisonData = {
    labels,

    datasets: [
      {
        label: 'Tempo médio de vida',
        data: methods.map((method) => method.tt),
        backgroundColor: 'rgba(54, 162, 235, 0.8)',
      },

      {
        label: 'Tempo médio de espera',
        data: methods.map((method) => method.tw),
        backgroundColor: 'rgba(255, 99, 132, 0.8)',
      },
    ],
  }

  const options = {
    responsive: true,

    scales: {
        x:{
            ticks: { color: '#ffffff' },
        },
        y: {
        beginAtZero: true,

        title: {
          display: true,
          text: 'Tempo (s)',
          color: '#ffffff',
        },
        ticks: { color: '#ffffff' },
        grid: { color: 'rgba(255, 255, 255, 0.1)' }
      },
    },

    plugins: {
      legend: {
        display: true,
        labels: {
          color: '#ffffff'
        }
      },
    },
  }

  return (
    <Card sx={{ border: '2px solid #1e1e1e', height: '100%', display: 'flex', flexDirection: 'column' }}>
        <CardHeader title="Comparação de desempenho" sx={{backgroundColor: "#121212"}}/>
        <CardMedia>
            <Bar
            data={comparisonData}
            options={options}
            />
        </CardMedia>
    </Card>

  )
}

export default ChartComparation