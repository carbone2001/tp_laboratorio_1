typedef struct
{
    int id;
    char name[51];
    char lastName[51];
    float salary;
    int sector;
    int isEmpty;
}Employee;

/** \brief Desplega el menu principal
 *
 * \return int La opcion tomada en base al menu
 *
 */
int menu();
/** \brief Se encarga de hacer el proceso de dar alta a un empleado
 *
 * \param list Employee* El vector de la estructura empleados
 * \param len int El tamanio del vector
 * \param contId int* Puntero hacia la variable que cuenta los ID
 * \return void
 *
 */
void altaEmpleado(Employee* list,int len,int* contId);
/** \brief Se encarga de modificar los datos del empleado
 *
 * \param list Employee* El vector de la estructura empleados
 * \param len int El tamanio del vector
 * \param contId int* Puntero hacia la variable que cuenta los ID
 * \return void
 *
 */
void modificarEmpleado(Employee* list,int len,int* contId);
/** \brief Se encarga de dar una baja logica a un empleado especificado por ID
 *
 * \param list Employee* El vector de la estructura empleados
 * \param len int El tamanio del vector
 * \param contId int* Puntero hacia la variable que cuenta los ID
 * \return void
 *
 */
void bajarEmpleado(Employee* list,int len,int* contId);
/** \brief Se encarga de desplegar el menu de informes y ejecutar las opciones seleccionadas
 *
 * \param list Employee* El vector de la estructura empleados
 * \param len int El tamanio del vector
 * \param contId int* Puntero hacia la variable que cuenta los ID
 * \return void
 *
 */
void informarEmpleados(Employee* list,int len,int* contId);
/** \brief To indicate that all position in the array are empty,
 * this function put the flag (isEmpty) in TRUE in all
 * position of the array
 * \param list Employee* Pointer to array of employees
 * \param len int Array length
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int initEmployees(Employee* list, int len);
/** \brief add in a existing list of employees the values received as parameters
 * in the first empty position
 * \param list employee*
 * \param len int
 * \param id int
 * \param name[] char
 * \param lastName[] char
 * \param salary float
 * \param sector int
 * \return int Return (-1) if Error [Invalid length or NULL pointer or without
free space] - (0) if Ok
 */
int addEmployee(Employee* list, int len, int id, char* name, char* lastName,float salary,int sector);
/** \brief find an Employee by Id en returns the index position in array.
 *
 * \param list Employee*
 * \param len int
 * \param id int
 * \return Return employee index position or (-1) if [Invalid length or NULL
pointer received or employee not found]
 *
 */
int findEmployeeById(Employee* list,int len,int id);
/** \brief Remove a Employee by Id (put isEmpty Flag in 1)
 *
 * \param list Employee*
 * \param len int
 * \param id int
 * \return int Return (-1) if Error [Invalid length or NULL pointer or if can't
find a employee] - (0) if Ok
 *
 */
int removeEmployee(Employee* list,int len,int id);
/** \brief Sort the elements in the array of employees, the argument order
indicate UP or DOWN order
 *
 * \param list Employee*
 * \param len int
 * \param order int [1] indicate UP - [0] indicate DOWN
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int sortEmployees(Employee* list,int len,int order);
/** \brief print the content of employees array
 *
 * \param list Employee*
 * \param length int
 * \return int
 *
 */
int printfEmployees(Employee* list,int len);

