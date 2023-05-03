#include <stdio.h>

/*La empresa Tumalla.com es un fabricante por excelencia de todo tipo de mallas deportivas
entre sus productos estrellas se encuentran las mallas de tenis y las mallas de beisbol
la gerencia requiere controlar las ventas por dia de acuerdo a las siguientes politicas:

Si el cliente tienes mas de 5 annos como comprador de mallas para beisbol tendra un
descuento del 8%, Si el comprador es de mallas para tenis tendra un descuento de 6%
El cliente que tenga un tiempo menor o igual a 5 annos no tendra descuento, si el
cliente tiene mas de 15 annos tendra un descuento del 30%.
El costo de las mallas para beisbol es de 50$ el metro
El costo de las mallas para beisbol es de 80$ el metro

1)Determinar el costo de la compra por cliente
2)El ingreso recibido por la empresa
3)La cantidad de mallas para beisbol vendidas
4)La cantidad de mallas para tenis vendidas
5)Cual de las dos mallas se vendio mas
6)Total de clientes que obtuvieron descuento
7)Cantidad total de descuento
8)Tota; de compras*/
    
	int csBaseball, csTennis, dia, produc, AnotherVenta, Annos, Total_descuClientes, compras;
	float precio, ingreso_empresa, Total_descu;
	float cantMBase,cantMTen,cant_MBaseTotal, cant_MTenTotal;

int main(){  
	
	ingreso_empresa = 0;
	compras = 0;
	Total_descuClientes = 0;
	Total_descu = 0;
	cantMBase = 0;
	cantMTen = 0;
	cant_MBaseTotal = 0;
	cant_MTenTotal = 0;
	csBaseball = 50;
	csTennis = 80;
	
	do{
		do{
			printf("Ingrese el dia\n");
			scanf("%d", &dia);
		}while(dia<0 || dia>31 );
		
		do{
			printf("Ingrese el producto a comprar\n [1]Mallas para beisbol\n [2]Mallas para tenis\n [3]Ambas\n");
			scanf("%d", &produc);
		}while(produc<1 || produc>3);
		
		if(produc == 1){
			printf("Ingrese la cantidad de metros de malla de beisbol\n");
			scanf("%g", &cantMBase);
			precio = cantMBase * csBaseball;
		}else if(produc == 2){
			printf("Ingrese la cantidad de metros de malla de tenis\n");
			scanf("%g", &cantMTen);
			precio = cantMTen * csTennis;
		}else if(produc == 3){
			printf("Ingrese la cantidad de metros de malla de beisbol\n");
			scanf("%g", &cantMBase);
			
			printf("Ingrese la cantidad de metros de malla de tenis\n");
			scanf("%g", &cantMTen);
			
			precio = (cantMBase * csBaseball)+ (cantMTen * csTennis); 
		}
		
		do{
			printf("Deme la cantidad de Annos que usted lleva comprando en la tienda\n");
			scanf("%d", &Annos);
		}while(Annos < 0);
		
		if(Annos > 15){
			precio = precio - (precio*(8/100));
			Total_descu = Total_descu + precio*(8/100);
			Total_descuClientes++;
		}else if(Annos > 5){
			precio = precio - (precio*(6/100));
			Total_descu = Total_descu + precio*(6/100);
			Total_descuClientes++;
		}
		
		cant_MBaseTotal = cant_MBaseTotal + cantMBase;
		cant_MTenTotal = cant_MTenTotal + cantMTen;
		ingreso_empresa = ingreso_empresa + precio;
		
		printf("El precio por compra del cliente es %g", precio);
		
		printf("Desea ingresar otra venta\n [1]Si\n [2]No\n");
		scanf("%d", &AnotherVenta);
		compras++;
	}while(AnotherVenta == 1);
	
	printf("El ingreso recibido de la empresa es %g\n", ingreso_empresa);
	printf("La cantidad de mallas de beisbol vendidas en mts es de %g\n", cant_MBaseTotal);
	printf("La cantidad de mallas de tenis vendidas en mts es de %g\n", cant_MTenTotal);
	
	if(cant_MBaseTotal > cant_MTenTotal){
		printf("Las mallas de beisbol se vendieron mas que las mallas de tenis\n");
	} else{
		printf("Las mallas de tenis se vendieron mas que las mallas de beisbol\n");
	} 
	
	printf("La cantidad de clientes con descuento es de %d\n", Total_descuClientes);
	printf("La cantidad total de descuento es %g\n", Total_descu);
	
	printf("Antonel Lopez C.I 30.020.199");
	return 0;
}
