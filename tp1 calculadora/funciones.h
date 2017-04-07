/** \brief Pide un numero y lo retorna
 * \param Pide la numero en la que se va a utilizar.
 * \return El numero ingresado por el scanf.
 */
int ingresarOperando();

/** \brief Suma dos valores
 *
 * \param Valor 1 de la suma
 * \param Valor 2 de la suma
 * \return Retorna la suma de Valor 1 y Valor 2
 */
void calcularsuma (int a, int b, int flaga, int flagb);

/** \brief Resta dos valores
 *
 * \param Valor 1 de la resta
 * \param Valor 2 de la resta
 * \return Retorna la resta de Valor 1 y Valor 2
 */
void calcularresta (int a, int b, int flaga, int flagb);

/** \brief Divide dos valores
 *
 * \param Valor 1 de la división
 * \param Valor 2 de la división
 * \return Retorna la división entre Valor 1 y Valor 2
 */
void calculardivision (int a, int b, int flaga, int flagb);

/** \brief Multiplica dos valores
 *
 * \param Valor 1 de la multiplicación
 * \param Valor 2 de la multiplicación
 * \return Retorna la multiplicación entre Valor 1 y Valor 2
 */
void calcularmultiplicacion (int a, int b, int flaga, int flagb);

/** \brief Factorial de un numero
 *
 * \param Valor 1 a factorear
 * \return Retorna el resultado del factoreo
 */
void calcularfactorial (int numero, int flaga);

/** \brief Muestra todas las operaciones por pantalla.
 * \param  Pide un valor integer que se deposita en A.
 * \param  Pide un valor integer que se deposita en B.
 */
vvoid llamarTodo (int a, int b, int flaga, int flagb)
