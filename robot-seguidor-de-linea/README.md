# Robot seguidor de línea

Robot seguidor de línea en dos etapas: primero con 2 sensores y driver L298N con control de velocidad por PWM, y después un velocista con regleta QTR-8A, driver TB6612FNG y control PID. Incluye el circuito y la PCB diseñados en Fritzing, con los archivos Gerber listos para fabricar.

**Herramientas:** Arduino, sensores CNY70 / QTR-8A, drivers L298N y TB6612FNG, control PID, Fritzing, Proteus

## Código

| Archivo | Qué es |
|---|---|
| [seguidorfinal/](<codigo/seguidorfinal>) | VERSIÓN FINAL del seguidor (18 jun 2023): 2 sensores, L298N con PWM y funciones de movimiento en la pestaña FP.ino. **versión final** |
| [ADA/](<codigo/ADA>) | Velocista con regleta QTR-8A, driver TB6612FNG, botón y LED; código repartido en 5 pestañas. |
| [seguidor_de_linea/](<codigo/seguidor_de_linea>) | Seguidor con 2 sensores IR digitales y 4 salidas a motores (abr 2024). |
| [SPEED_PROGRAMA_PID-1/](<codigo/SPEED_PROGRAMA_PID-1>) | Mi adaptación del PID con botones de calibración/arranque (11 jun 2023). _basado en el código de Rodrigo Rolly Flores Huanca_ |

### Versiones anteriores y pruebas

Muestran cómo fue evolucionando el proyecto.

| Archivo | Qué es |
|---|---|
| [SEGUIDOR_3/](<codigo/versiones/SEGUIDOR_3>) | Seguidor de 2 sensores con L298N y velocidad por PWM (12 jun 2023). |

## Simulaciones

| Archivo | Qué es |
|---|---|
| [PLACA_PCB_BLACK_RACER.pdsprj](<simulaciones/PLACA_PCB_BLACK_RACER.pdsprj>) | PCB "Black Racer" (jun 2023). (Proteus) |
| [seguidor de linea 1.0.fzz](<simulaciones/seguidor de linea 1.0.fzz>) | Circuito y PCB del seguidor de línea (nov 2021). (Fritzing) |

## PCB

| Archivo | Qué es |
|---|---|
| [GERBER/](<pcb/GERBER>) | Archivos Gerber y de taladrado para mandar a fabricar la PCB del seguidor. |
| [IMPIRMIR/](<pcb/IMPIRMIR>) | PDFs de las pistas de cobre para hacer la PCB por planchado. |

> `SPEED_PROGRAMA_PID-1` es una adaptación propia del código de Rodrigo Rolly Flores Huanca.

[← Volver al índice](../README.md)
