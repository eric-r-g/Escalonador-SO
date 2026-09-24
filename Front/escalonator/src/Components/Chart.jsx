import { Bar } from 'react-chartjs-2'

import { Paper } from '@mui/material'

import {
  Chart as ChartJS,
  CategoryScale,
  LinearScale,
  BarElement,
  Tooltip,
  Legend,
} from 'chart.js'

ChartJS.register(
  CategoryScale,
  LinearScale,
  BarElement,
  Tooltip,
  Legend
)

function Chart({ data }) {
  if (!data || !data.intervalos) return <p>Carregando gráfico...</p>
    
  const intervals = data.intervalos

  const chartData = {
    datasets: [
      {
        label: 'Execução',
        data: intervals.map((interval) => ({
          y: `P${interval.id}`,
          x: [interval.ini, interval.fim],
        })),
        backgroundColor: intervals.map((interval) => {
          const colors = {
            1: 'rgba(54, 162, 235, 0.8)',
            2: 'rgba(255, 99, 132, 0.8)',
            3: 'rgba(75, 192, 192, 0.8)',
            4: 'rgba(255, 206, 86, 0.8)',
          }

          return colors[interval.id] || 'rgba(150, 150, 150, 0.8)'
        }),
        borderWidth: 1,
      },
    ],
  }

  const chartOptions = {
    indexAxis: 'y',

    responsive: true,

    scales: {
      x: {
        min: 0,

        title: {
          display: true,
          text: 'Tempo (s)',
        },
      },

      y: {
        title: {
          display: true,
          text: 'Processos',
        },

        offset: true,
      },
    },

    plugins: {
      legend: {
        display: false,
      },

      tooltip: {
        callbacks: {
          label: (context) => {
            const interval = intervals[context.dataIndex]

            return `P${interval.id}: ${interval.ini}s → ${interval.fim}s`
          },
        },
      },
    },
}

    return(
        <>
            <Paper elevation={3} sx={{ p: 4, borderRadius: 2, backgroundColor: '#ffffff' }}>
                <Bar
                data={chartData}
                options={chartOptions}
                />
            </Paper>
        </>
    )
}

export default Chart