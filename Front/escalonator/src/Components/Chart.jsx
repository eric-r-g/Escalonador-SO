import { Bar } from 'react-chartjs-2'

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
    
  const intervals = data.intervalos;
  const maxTime = Math.max(...intervals.map((interval) => interval.fim));
  const colors = [
            'rgba(54, 162, 235, 0.8)',
            'rgba(255, 99, 132, 0.8)',
            'rgba(75, 192, 192, 0.8)',
            'rgba(255, 206, 86, 0.8)',
            'rgba(153, 102, 255, 0.8)',
            'rgba(255, 159, 64, 0.8)',
        ];

  const chartData = {
    datasets: [
      {
        label: 'Execução',
        data: intervals.map((interval) => ({
          y: `P${interval.id}`,
          x: [interval.ini, interval.fim],
        })),
        
        backgroundColor: intervals.map((interval) => {
          const idNum = Number(interval.id) || 0;
          
          const index = Math.max(0, idNum); 
          
          return colors[index % colors.length];
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
        max: maxTime,
        title: {
          display: true,
          text: 'Tempo (s)',
          color: '#ffffff',
        },
        ticks: { color: '#ffffff' },
        grid: { color: 'rgba(255, 255, 255, 0.1)' }
      },

      y: {
        title: {
          display: true,
          text: 'Processos',
          color: '#ffffff',
        },
        ticks: { color: '#ffffff' },
        grid: { color: 'rgba(255, 255, 255, 0.1)' },
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
          <Bar
          data={chartData}
          options={chartOptions}
          />
        </>
    )
}

export default Chart