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
	// INICIALITZACIONS
	// Obrim el socket
	si ((sock_listen = socket (AF_INET, SOCK_STREAM, 0 )) < 0 )
		printf ( " Error al crear socket " );
	// Fem el bind al port
	
	
	memset (y serv_adr, 0 , sizeof (serv_adr)); // inicialitza a cero serv_addr
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
			
			char nombre [ 20 ];
			
			si (codigo! = 0 )
			{
				p = strtok ( NULL , " / " );
				
				strcpy (nombre, p);
				
				printf ( " Codigo: % d , Nombre: % s \ n " , codigo, nombre);
			}
			
			si (codigo == 0 )
			{
				terminar = 1 ;
			}
			
			if (codigo == 1 ) // piden la longitd del nombre
			{
				sprintf (respuesta, " % ld " , strlen (nombre));
			}
			
			más  si (codigo == 2 )
			{
				// quieren saber si el nombre es bonito
				if ((nombre [ 0 ] == ' M ' ) || (nombre [ 0 ] == ' S ' ))
				{
					strcpy (respuesta, " SI " );
				}
				más
				{
					strcpy (respuesta, " NO " );
				}
			}
			else   if (codigo == 3 ) // quiere saber si es alto
			{
				p = strtok ( NULL , " / " );
				flotar altura =   atof (p);
				si (altura> 1,70 )
					sprintf (respuesta, " % s : eres alto " , nombre);
				más
					sprintf (respuesta, " % s : eresbajo " , nombre);
			}
			
			else   if (codigo == 4 ) // palindromo
			{		
				
				int pal = 1 ;
				int lenn = strlen (nombre);
				para ( int l = 0 ; nombre [l]! = ' \ 0 ' ; l = l + 1 )
				{
					nombre [l] = toupper (nombre [l]);
				}
				
				si (lenn% 2 == 0 )
				{
					para ( int i = 0 ; i <= (lenn- 1 ) / 2 ; i ++)
					{
						if (nombre [i]! = nombre [lenn- 1 -i])
							pal = 0 ;
					}
				}
				si (lenn% 2 == 1 )
				{
					para ( int i = 0 ; i <= (lenn - 2 ) / 2 ; i ++)
					{
						if (nombre [i]! = nombre [lenn- 1 -i])
							pal = 0 ;
					}
				
				}
				si (pal == 1 )
				{
					strcpy (respuesta, " SI " );
				}
				más
					strcpy (respuesta, " NO " );
				
				
			}				
			
			else   if (codigo == 5 ) // mayusculas
			{		
				
				int pal = 1 ;
				int lenn = strlen (nombre);
				para ( int l = 0 ; nombre [l]! = ' \ 0 ' ; l = l + 1 )
				{
					nombre [l] = toupper (nombre [l]);
				}
				strcpy (respuesta, nombre);
				
				
			}				
			
			si (codigo! = 0 )
			{
				
				printf ( " Respuesta: % s \ n " , respuesta);
				// Enviamos respuesta
				escribir (sock_conn, respuesta, strlen (respuesta));
			}
			
		}
		// Se acabo el servicio para este cliente
		cerrar (sock_conn);
	}
}

