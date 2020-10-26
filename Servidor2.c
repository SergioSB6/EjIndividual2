# incluir  < string.h >
# incluir  < unistd.h >
# incluye  < stdlib.h >
# incluye  < sys / types.h >
# incluye  < sys / socket.h >
# incluye  < netinet / in.h >
# incluye  < stdio.h >
# incluye  < ctype.h >



int  main ( int argc, char * argv [])
{
	
	int sock_conn, sock_listen, ret;
	struct sockaddr_in serv_adr;
	char peticion [ 512 ];
	char respuesta [ 512 ];
	si ((sock_listen = socket (AF_INET, SOCK_STREAM, 0 )) < 0 )
		printf ( " Error al crear socket " );
	
	
	
	memset (y serv_adr, 0 , sizeof (serv_adr)); 
	serv_adr. sin_family = AF_INET;
	

	serv_adr. sin_addr . s_addr = htonl ( INADDR_ANY );
	// establecemos el puerto de escucha
	serv_adr. puerto_sin = htons ( 50055 );
	if ( bind (sock_listen, ( struct sockaddr *) & serv_adr, sizeof (serv_adr)) < 0 )
		printf ( " Error al enlazar " );
	
	si ( escuchar (sock_listen, 3 ) < 0 )
		printf ( " Error en el Escuchar " );
	
	int i;
	
	
	para (;;) {
		printf ( " Escuchando \ n " );
		
		sock_conn = aceptar (sock_listen, NULL , NULL );
		printf ( " Recibió conexión \ n " );
		
		int terminar = 0 ;
		while (terminar == 0 )
		{
			
			ret = leer (sock_conn, peticion, sizeof (peticion));
			printf ( " Recibido \ n " );
			
			
			peticion [ret] = ' \ 0 ' ;
			
			
			
			
			char * p = strtok (peticion, " / " );
			printf ( " Peticion: % s \ n " , peticion);
			
			int codigo =   atoi (p);
			
			flotar temp2;
			temperatura de flotación ;
			
			si (codigo! = 0 )
			{
				p = strtok ( NULL , " / " );
				
				temp = atoi (p);
				// Ya tenemos la temperatura
			}
			
			si (codigo == 0 )
			{
				terminar = 1 ;
			}
			
	else  if (codigo == 1 ) //Celsius
	{
		temp2 = temp * 1.8 + 32 ;
		sprintf (respuesta, " % f " , temp2);
	}
	
	else  if (codigo == 2 ) //Fahrenheit
	{
		temp2 = (temp - 32 ) / 1.8 ;
		sprintf (respuesta, " % f " , temp2);
	}
	
	
	si (codigo! = 0 )
	{
		
		printf ( " Respuesta: % s \ n " , respuesta);
		// Enviamos respuesta
		escribir (sock_conn, respuesta, strlen (respuesta));
	}
	
		}
	
		cerrar (sock_conn);
	}
}
