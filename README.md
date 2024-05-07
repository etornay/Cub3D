_Los objetivos de este proyecto son:
Rigor, uso de C, uso de algoritmos básicos, investigación de información, etc. Como proyecto de diseño gráfico, cub3D te permitirá mejorar tus habilidades en estas áreas:
ventanas, colores, eventos, rellenar formas, etc. En resumen, cub3D es un notable campo de juegos para explorar las aplicaciones prácticas y lúdicas de las matemáticas sin necesidad de entender los detalles específicos. Con la ayuda de los numerosos documentos disponibles en Internet, utilizarás las matemáticas como herramienta para crear algoritmos elegantes y eficientes._

* ENLACE GUÍA/TUTORIAL: https://medium.com/@afatir.ahmedfatir/cub3d-tutorial-af5dd31d2fcf

* ENLACE VÍDEO EXPLICANDO RAYCASTING: https://www.youtube.com/watch?v=awXyP0g91mE

<h1>1. Instrucciones generales:</h1>

• Debes usar MLX. Ya sea la versión disponible en el sistema operativo o desde sus fuentes. Si eliges trabajar con las fuentes, deberás aplicar las mismas reglas para tu libft que las escritas anteriormente en la parte de Instrucciones Comunes.

• El manejo de tu ventana debe ser suave: cambiar a otra ventana, minimizar, etc.

• Mostrar diferentes texturas de pared (la elección es tuya) que varíen según el lado hacia el que esté orientada la pared (Norte, Sur, Este, Oeste).

• Tu programa debe poder establecer los colores del suelo y del techo en dos colores diferentes.

• El programa muestra la imagen en una ventana y respeta las siguientes reglas:

• Las teclas de flecha izquierda y derecha del teclado te permiten mirar a la izquierda y a la derecha en el laberinto.

• Las teclas W, A, S y D te permiten mover el punto de vista a través del laberinto.

• Presionar ESC debe cerrar la ventana y salir del programa correctamente.

• Hacer clic en la cruz roja en el marco de la ventana debe cerrar la ventana y salir del programa correctamente.

• Se recomienda encarecidamente el uso de imágenes de MLX.

• Tu programa debe tomar como primer argumento un archivo de descripción de escena con la extensión .cub.

• El mapa debe estar compuesto solo por 6 caracteres posibles: 0 para un espacio vacío, 1 para una pared, y N, S, E o W para la posición de inicio y orientación del jugador.

• El mapa debe estar cerrado/rodeado por paredes, si no, el programa debe devolver un error.

• Excepto por el contenido del mapa, cada tipo de elemento puede estar separado por una o más líneas vacías.

• Excepto por el contenido del mapa, que siempre debe ser el último, cada tipo de elemento puede estar configurado en cualquier orden en el archivo.

• Excepto por el mapa, cada tipo de información de un elemento puede estar separado por uno o más espacios.

• El mapa debe ser analizado tal como aparece en el archivo. Los espacios son una parte válida del mapa y depende de ti manejarlos. Debes poder analizar cualquier tipo de mapa, siempre y cuando respete las reglas del mapa.

•  El primer elemento de cada elemento (excepto el mapa) es el identificador del tipo (compuesto por uno o dos caracteres), seguido de toda la información específica para cada objeto en un orden estricto, como:

◦ Textura Norte:

* NO ./path_to_the_north_texture

◦ Textura Sur:

* SO ./path_to_the_south_texture

◦ Textura Oeste:

* WE ./path_to_the_weast_texture

◦ Textura Este:

* EA ./path_to_the_east_texture

◦ Color del suelo:

* F 220,100,0

◦ Color del cielo:

* C 225,30,0

• Ejemplo de la parte obligatoria con un archivo .cub minimalista:

1111111111111111111111111

1000000000110000000000001

1011000001110000000000001

1001000000000000000000001

111111111011000001110000000000001

100000000011000001110111111111111
11110111111111011100000010001

11110111111111011101010010001

11000000110101011100000010001

10000000000000001100000010001

10000000000000001101010010001

11000001110101011111011110N0111

11110111 1110101 101111010001

11111111 1111111 111111111111

• Si se encuentra alguna mala configuración de cualquier tipo en el archivo, el programa debe salir correctamente y devolver "Error\n" seguido de un mensaje de error explícito de tu elección.

<h1>2. Bonus:</h1>

• Colisiones con paredes.

• Un sistema de minimapa.

• Puertas que pueden abrirse y cerrarse.

• Sprite animado.

• Rotar el punto de vista con el mouse.
