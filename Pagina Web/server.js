const LoginCuenta = require('./Node'); // Asegúrate de que la ruta sea correcta

const express = require('express');
const app = express();
app.use(express.json());

const loginCuenta = new LoginCuenta();

app.post('/crearCuenta', (req, res) => {
    const { nombre, apellido, correo, clave, edad, identificacion } = req.body;
    loginCuenta.crearCu(nombre, apellido, correo, clave, edad, identificacion);
    res.json({ message: "Cuenta creada" });
});

app.post('/iniciarSesion', (req, res) => {
    const { correo, clave } = req.body;
    loginCuenta.iniciarSe(correo, clave);
    res.json({ message: "Inicio de sesión intentado" });
});

const PORT = 3000;
app.listen(PORT, () => {
    console.log(`Servidor corriendo en el puerto ${PORT}`);
});
