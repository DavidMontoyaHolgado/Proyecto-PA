const fs = require('fs');

class LoginCuenta {
    crearCu(nombre, apellido, correo, clave, edad, identificacion) {
        const usuarios = this._leerUsuarios();
        if (usuarios.some(u => u.correo === correo)) {
            console.log(`El correo ${correo} ya existe`);
            return;
        }

        // Agregar el usuario nuevo
        const nuevoUsuario = { nombre, apellido, correo, clave, edad, identificacion };
        usuarios.push(nuevoUsuario);
        this._guardarUsuarios(usuarios);
        console.log("Cuenta creada exitosamente");
    }

    iniciarSe(correo, clave) {
        const usuarios = this._leerUsuarios();
        const usuario = usuarios.find(u => u.correo === correo && u.clave === clave);
        if (usuario) {
            console.log("Bienvenido al sistema");
        } else {
            console.log("El Correo y/o la clave son incorrectas");
        }
    }

    _leerUsuarios() {
        // Leer el archivo y convertirlo en objetos
        const data = fs.readFileSync('usuarios.txt', 'utf8');
        return data.split('\n').map(line => {
            const [id, nombre, correo, clave, edad, identificacion] = line.split(' ');
            return { id, nombre, correo, clave, edad, identificacion };
        });
    }

    _guardarUsuarios(usuarios) {
        // Convertir los objetos de usuario en strings y guardarlos en el archivo
        const data = usuarios.map(u => `${u.id} ${u.nombre} ${u.correo} ${u.clave} ${u.edad} ${u.identificacion}`).join('\n');
        fs.writeFileSync('usuarios.txt', data, 'utf8');
    }
}
module.exports = LoginCuenta;
