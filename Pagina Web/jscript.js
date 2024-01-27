// Ejemplo: Mostrar un mensaje cuando se añade un producto al carrito
function addToCart(productName) {
    alert(productName + " ha sido añadido al carrito.");
}


// En producto.html, ejecutar esta función al cargar la página
function loadProductDetails() {
    const urlParams = new URLSearchParams(window.location.search);
    const productId = urlParams.get('product'); // Obtiene el ID del producto de la URL

    // Aquí iría la lógica para obtener los detalles del producto basándose en el productId
    // Por ejemplo, podrías tener un arreglo de productos y buscar el correcto por su ID
    
  
// Luego actualizas el DOM con la información del producto
}

// Asegúrate de llamar a loadProductDetails en producto.html
if (window.location.pathname.includes('producto.html')) {
    
    loadProdu
loadProductDetails();
}


$(document).ready(function(){
    $("#loginButton").click(function(){
      function iniciarSesion() {
        var correo = document.getElementById('loginEmail').value;
        var clave = document.getElementById('loginPassword').value;
    
        fetch('/iniciarSesion', {
            method: 'POST',
            headers: {
                'Content-Type': 'application/json',
            },
            body: JSON.stringify({ correo, clave })
        })
        .then(response => response.json())
        .then(data => {
            alert(data.message); // Manejar la respuesta del servidor aquí
        })
        .catch(error => console.error('Error:', error));
    }
    
    function crearCuenta() {
        var correo = document.getElementById('registerEmail').value;
        var clave = document.getElementById('registerPassword').value;
        var nombre = document.getElementById('registerFirstName').value;
        var apellido = document.getElementById('registerLastName').value;
        // Añade aquí más campos si es necesario
    
        fetch('/crearCuenta', {
            method: 'POST',
            headers: {
                'Content-Type': 'application/json',
            },
            body: JSON.stringify({ nombre, apellido, correo, clave })
        })
        .then(response => response.json())
        .then(data => {
            alert(data.message); // Manejar la respuesta del servidor aquí
        })
        .catch(error => console.error('Error:', error));
    }
    
    // Vinculación de eventos a botones
    $(document).ready(function(){
        $("#loginButton").click(function(){
            iniciarSesion();
        });
    
        $("#registerButton").click(function(){
            crearCuenta();
        });
  });
})});
