# Estacionamiento automatizado

Estacionamiento que cuenta los autos con sensores infrarrojos, muestra los lugares disponibles en un display de 7 segmentos y abre la pluma con un servomotor (febrero de 2024).

**Herramientas:** Arduino, sensores infrarrojos, sensor ultrasónico, servomotor, display de 7 segmentos

## Código

| Archivo | Qué es |
|---|---|
| [PRUEBA_FINAL_1/](<codigo/PRUEBA_FINAL_1>) | VERSIÓN FINAL (20 feb 2024): 2 sensores IR cuentan autos (bloqueo de 5 s), display de 7 segmentos con los lugares y servo como pluma. **versión final** |
| [estacionamiento_version_infrarrojos_1/](<codigo/estacionamiento_version_infrarrojos_1>) | Versión con 2 sensores IR y servo, sin display (20 feb). |

### Versiones anteriores y pruebas

Muestran cómo fue evolucionando el proyecto.

| Archivo | Qué es |
|---|---|
| [estacionamiento_proyecto/](<codigo/versiones/estacionamiento_proyecto>) | Primera versión del proyecto: botones + display + servo (17 feb). |
| [servo/](<codigo/versiones/servo>) | Servo como puerta controlada por ultrasónico. |
| [sketch_feb16a/](<codigo/versiones/sketch_feb16a>) | Servo que abre cuando el ultrasónico detecta algo a menos de 30 cm. |
| [sketch_feb16b/](<codigo/versiones/sketch_feb16b>) | Ultrasónico + servo + contador en display (16 feb). |
| [sketch_feb19b/](<codigo/versiones/sketch_feb19b>) | Prueba del sensor infrarrojo: enciende un LED al detectar algo. |
| [sketch_feb19g/](<codigo/versiones/sketch_feb19g>) | 2 sensores IR + servo (19 feb). |

[← Volver al índice](../README.md)
