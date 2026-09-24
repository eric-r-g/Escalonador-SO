import { useState } from 'react';
import { 
  Box, 
  Paper, 
  Typography, 
  TextField, 
  Button, 
  Grid, 
  Stack
} from '@mui/material';

import CloudUploadIcon from '@mui/icons-material/CloudUpload';

function Input() {
  const [manualText, setManualText] = useState('');
  const [fileName, setFileName] = useState('');

  const handleFileUpload = (event) => {
    const file = event.target.files[0];
    if (file) {
      setFileName(file.name);
      
      const reader = new FileReader();
      reader.onload = (e) => {
        const content = e.target.result;
        setManualText(content); 
      };
      reader.readAsText(file);
    }
  };

  const handleClear = () => {
    setManualText('');
    setFileName('');
  };

  const handleSubmit = () => {

    const config = {
      processData: manualText
    };
    
  };

  return (
    <Paper elevation={3} sx={{ p: 4, borderRadius: 2, backgroundColor: '#ffffff' }}>
        <Box sx={{ display: 'flex', flexDirection: 'column', alignItems: 'center', justifyContent: 'center', maxWidth: '900px', margin: '0 auto' }}>
            <Box sx={{ display: 'flex', flexDirection: 'column', alignItems: 'center', justifyContent: 'center', gap: 4, width: '100%', marginBottom: 2 }}>
                <Grid container spacing={4}>
                    <Grid item xs={12} md={6}>
                    <Typography variant="subtitle2" sx={{ mb: 1, fontWeight: 'bold' }}>
                        FILE UPLOAD (.TXT)
                    </Typography>
                    
                    <Button
                        component="label"
                        sx={{
                        width: '100%',
                        height: '250px',
                        border: '2px dashed #1976d2',
                        borderRadius: 2,
                        display: 'flex',
                        flexDirection: 'column',
                        backgroundColor: '#f8faff',
                        color: '#1976d2',
                        '&:hover': {
                            backgroundColor: '#eff4ff',
                            border: '2px dashed #1565c0',
                        }
                        }}
                    >
                        <CloudUploadIcon sx={{ fontSize: 60, mb: 2 }} />
                        <Typography variant="body1" sx={{ textTransform: 'none' }}>
                        {fileName ? `Arquivo: ${fileName}` : "Arraste um arquivo .txt ou clique para selecionar."}
                        </Typography>
                        <input
                        type="file"
                        accept=".txt"
                        hidden
                        onChange={handleFileUpload}
                        />
                    </Button>
                    <Typography variant="caption" color="text.secondary" sx={{ display: 'block', mt: 1 }}>
                        Apenas arquivos de texto puro (.txt) são suportados.
                    </Typography>
                    </Grid>

                    <Grid item xs={12} md={6}>
                    <Typography variant="subtitle2" sx={{ mb: 1, fontWeight: 'bold' }}>
                        ENTRADA DE TEXTO MANUAL
                    </Typography>
                    
                    <TextField
                        multiline
                        rows={9}
                        fullWidth
                        placeholder="Exemplo de entrada:&#10;0 5 2&#10;0 2 3&#10;1 4 1&#10;3 3 4"
                        value={manualText}
                        onChange={(e) => setManualText(e.target.value)}
                        variant="outlined"
                        sx={{
                        '& .MuiOutlinedInput-root': {
                            backgroundColor: '#ffffff',
                        }
                        }}
                    />
                    <Box sx={{ display: 'flex', mt: 1 }}>
                        <Button size="small" variant="contained" color="info" onClick={handleClear} disableElevation>
                        Limpar Texto
                        </Button>
                    </Box>
                    </Grid>
                </Grid>
            </Box>
            <Box sx={{ display: 'flex', alignItems: 'center', justifyContent: 'center', gap: 4, width: '100%' }}>
                <Stack direction="row" spacing={2} justifyContent="flex-end" sx={{ mt: 4 }}>
                    <Button variant="contained" color="inherit" onClick={handleClear}>
                    Resetar
                    </Button>
                    <Button variant="contained" color="primary" onClick={handleSubmit} size="large">
                    Simular Processos
                    </Button>
                </Stack>
            </Box>
        </Box>
    </Paper>
  );
}

export default Input;