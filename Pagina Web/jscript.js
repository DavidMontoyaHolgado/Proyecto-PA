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