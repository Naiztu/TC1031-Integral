
<a href="#">
    <img src="https://javier.rodriguez.org.mx/itesm/2014/tecnologico-de-monterrey-black.png" alt="ITESM" title="ITESM" align="right" height="60" />
</a>

# **MC Burguer** 🍔

#### **_TC1031-Integral_**
Repositorio dedicado al proyecto integral de la materia Programación de estructuras de datos y algoritmos fundamentales

## **Competencias empleadas para evaluar:** ✅
**SICT0302B:**
* _Selecciona un algoritmo de ordenamiento adecuado al problema_
* _Selecciona y usa una estructura lineal adecuada al problema_
* _Usa un árbol adecuado para resolver un problema_


**SICT0303B:**
* _Implementa mecanismos para consultar información de las estructras correctos_
* _Implementa mecanismos de lectura de archivos correctos_
* _Implementa mecanismos de escritura de archivos correctos_


## **Logica inicial** ⚙️ 
### **Primera Opción:**
_Correspondiente al primer avance, se intenta implementar un sistema para que el servicio de comida rápida sea más eficiente. Hay tres tipos de pedidos:_
*   _Mostrador, en la sucursal_
*   _Deliveri, todos los pedidos de aplicaciones._
*   _Auto, servicio de autoservicio._

_Cada uno tiene una importancia definida, al que se le tiene entregar más rápido es al auto, ya que es el que tiene menos tiempo, después sigue el del mostrador, para que el que menor prioridad en  el tiempo de entrega es el deliveri. Considerando esto, se necesita ordenar dependiendo la importancia del pedido para mandárselo a las pantallas de cocina_


### **Segunda Opción:** 
_Se desea saber el menú que se encuentra y desplegarlo para presentarlo o recordar los atributos que pertenecen al mismo: nombre, precio, id. Como siempre se muestra todos los articulos, se opto por una lista._


### **Tercera Opción:** 
_En caso que se necesite recomendar una hamburguesa, cada una tiene un numero de relación, que identifica que tanto se relacionan con otras. Como la mayoría de las personas escogerían lo más común, se optó por un árbol splay que reduzca los pasos._


## **Análisis de complejidad** 📈 

*   ### **Método Merge / sorts.h**
    _El algoritmo empleado en esta función, se apoya con un vector auxiliar, y al pasar el resultado de uno a otro, crea una complejidad de O(n), mientras que en otra parte va haciendo operaciones donde los pasos se reducen a la mitad conforme se acomoda, lo que genera una complejidad d O(Log(n)). Juntando estos dos casos, identificamos que la complejidad es de O(n Log(n))_
*   ### **Lista / Productos**
    _Como siempre se muestra todo el menú, se necesita iterar toda la lista, por lo que se entiende por una complejidad de O(n)._
*   ### **Arbol Splay**
    _Para agregar al árbol se usa un método con complejidad O(log(n)), ya que cada vez los pasos para saber en qué lugar colocar el objeto._

    _Para encontrar un objeto, tambien solo es necesarion una complejidad de O(log(n)), al igual que el agregar, se van haciendo los pasos mas chicos._


## **Correciones y notas** 📌
* _**Primer avance:** Completo._

* _**Segundo avance:** Se agrego la estructura lineal._

* _**Tercer avance:** Se agrego la estructura de arbol Splay._

* _Se agregaron los caso de prueba, el segundo solo funciona en la primera corrida sin modificar los pedidos._

* _Todoslos metodos usados para la aplicación, se encuentran el el archivo "app.h"_

## **Lenguaje** 👅
*  *C++*

## **Autor** ✒️
_Este proyecto es realizado para la UF "Programación de estructuras de datos y algoritmos fundamentales" (TC1031) por:_
* **José Ángel Rico Mendieta** - *A01707404*
