# Robot minisumo

Robot minisumo autónomo para competencia. Detecta al rival con sensores ultrasónicos y el borde del dojo con sensores infrarrojos, y lo empuja con dos motores DC controlados por puente H. Desarrollado entre noviembre de 2023 y junio de 2024: aquí está la evolución del código, la simulación en Proteus y el diseño de la PCB.

**Herramientas:** Arduino, sensores ultrasónicos HC-SR04, sensores infrarrojos, puente H, Proteus, diseño de PCB

## Código

| Archivo | Qué es |
|---|---|
| [SUMO_FINAL_4/](<codigo/SUMO_FINAL_4>) | VERSIÓN FINAL del minisumo (4 abr 2024): 2 ultrasónicos + 2 IR de borde; la más completa y comentada. **versión final** |
| [minisumo_con_ultra/](<codigo/minisumo_con_ultra>) | Minisumo solo con ultrasónicos, distancia de ataque de 20 cm (may 2024). |
| [PROTO4/](<codigo/PROTO4>) | Última modificación del minisumo (15 jun 2024), sobre la base de proto3. |

### Versiones anteriores y pruebas

Muestran cómo fue evolucionando el proyecto.

| Archivo | Qué es |
|---|---|
| [mi_progra/](<codigo/versiones/mi_progra>) | Adaptación de un código de minisumo publicado en internet, con mi propio cálculo de distancia. |
| [prueba1/](<codigo/versiones/prueba1>) | Prototipo de minisumo (nov 2023): ultrasónico + 2 IR (delantero/trasero) + 2 motores. |
| [robotsumo/](<codigo/versiones/robotsumo>) | Minisumo v1 (12 nov 2023): 3 sensores IR de línea + ultrasónico; busca y empuja al rival. |
| [sketch_nov11a/](<codigo/versiones/sketch_nov11a>) | Prueba del sensor ultrasónico: mide la distancia y la imprime. |
| [sketch_nov12a/](<codigo/versiones/sketch_nov12a>) | Minisumo con ultrasónico, 3 IR y L298N con ENA/ENB. |
| [yp/](<codigo/versiones/yp>) | Prototipo de minisumo (nov 2023): ultrasónico + 2 IR (delantero/trasero) + 2 motores. |

## Simulaciones

| Archivo | Qué es |
|---|---|
| [minisumo.pdsprj](<simulaciones/minisumo.pdsprj>) | Circuito del robot minisumo. (Proteus) |
| [sumo.pdsprj](<simulaciones/sumo.pdsprj>) | Circuito del robot minisumo. (Proteus) |

## PCB

| Archivo | Qué es |
|---|---|
| [PCB_PCB_minisumo_5_2024-04-13.pdf](<pcb/PCB_PCB_minisumo_5_2024-04-13.pdf>) | Documentación y diseño de la PCB del minisumo (abr 2024). |
| [PCB_PCB_New-Project_2024-04-01.pdf](<pcb/PCB_PCB_New-Project_2024-04-01.pdf>) | Documentación y diseño de la PCB del minisumo (abr 2024). |

## Documentos

| Archivo | Qué es |
|---|---|
| [minisumo.pdf](<documentos/minisumo.pdf>) | Documentación y diseño de la PCB del minisumo (abr 2024). |
| [placa del minisumo version final.pdf](<documentos/placa del minisumo version final.pdf>) | Documentación y diseño de la PCB del minisumo (abr 2024). |

> `mi_progra` parte de un código de minisumo publicado en internet, adaptado con mi propio cálculo de distancia.

[← Volver al índice](../README.md)
