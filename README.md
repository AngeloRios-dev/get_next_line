# get_next_line
The goal of this project is simple: program a function that returns a line read from a file descriptor.

## read_until_newline

Descripción:
read_until_newline es una función auxiliar encargada de leer datos desde un file descriptor (fd) en bloques de tamaño BUFFER_SIZE hasta encontrar un salto de línea (\n) o alcanzar el final del archivo. Su objetivo es acumular datos de manera progresiva sin leer más de lo necesario, almacenándolos en un stash intermedio reutilizable entre llamadas a get_next_line.

Características clave:

   - Utiliza read() en un bucle controlado por la presencia de \n en el stash.

   - Si ocurre un error de lectura o de memoria, devuelve NULL.

   - Devuelve un nuevo stash actualizado con el contenido previamente leído más lo nuevo.

## append_buffer

Descripción:
ft_append_buffer concatena el contenido actual del stash con los nuevos datos leídos desde el buffer, asegurando la correcta reserva de memoria y la liberación de la memoria anterior. Es una función de apoyo que encapsula la lógica de concatenación dinámica segura.

Características clave:

   - Termina correctamente el buffer con \0 antes de concatenar.

   - Libera el stash anterior para evitar fugas de memoria.

   - Devuelve el nuevo stash resultante de la unión, o NULL en caso de fallo.