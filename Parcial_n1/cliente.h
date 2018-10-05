
typedef struct
{
 int id;
 char nombre[51];
 char apellido[51];
 char cuit[51];
 int isEmpty;
}Cliente;

int initCliente(Cliente* array, int limite);
int cliente_alta(Cliente* array,int limite);
int cliente_modificacion(Cliente* array,int limite, int id);
int cliente_baja(Cliente* array,int limite, int id);
int cliente_buscarPorId(Cliente* array,int limite, int id);


