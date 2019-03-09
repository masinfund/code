#pragma once

#ifdef __cplusplus
extern "C"

{
	#endif 

// 接口

	int socketClient_init(void** handle) ;

	int socketClient_send(void* handle , void* buf , int len) ;

	int socketClient_recv(void* handle , void** buf , int* len) ;

	int socketClient_free(void** buf ) ;
	
	int socketClient_destroy(void* handle) ;






#ifdef __cplusplus

}
#endif 
