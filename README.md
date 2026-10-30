# Portafolio de Mecatrónica — César Augusto Morales Sánchez

Proyectos y prácticas que desarrollé como **Técnico en Mecatrónica** durante el bachillerato (2021-2024): robótica con Arduino, electrónica analógica y digital, neumática e hidráulica, control eléctrico, CNC y dibujo técnico.

## Proyectos

| Proyecto | Descripción |
|---|---|
| [Robot minisumo](robot-minisumo/) | Robot minisumo autónomo para competencia. |
| [Robot seguidor de línea](robot-seguidor-de-linea/) | Robot seguidor de línea en dos etapas: primero con 2 sensores y driver L298N con control de velocidad por PWM, y después un velocista con regleta QTR-8A, driver TB6612FNG y control PID. |
| [Estacionamiento automatizado](estacionamiento-automatizado/) | Estacionamiento que cuenta los autos con sensores infrarrojos, muestra los lugares disponibles en un display de 7 segmentos y abre la pluma con un servomotor (febrero de 2024). |
| [Control de motores paso a paso](motores-paso-a-paso/) | Control de dos motores paso a paso con tres pulsadores desde Arduino (junio de 2024), con su simulación en Proteus y el reporte del proyecto. |
| [Cubo LED 3x3x3](cubo-led-3x3x3/) | Cubo de 27 LEDs multiplexado por niveles, con animaciones programadas en Arduino (marzo de 2024). |
| [Carrito Bluetooth](carrito-bluetooth/) | Carrito controlado desde el celular por Bluetooth: el Arduino recibe comandos por el puerto serie y maneja dos motores con el driver L293B (septiembre de 2023). |
| [Prácticas de Arduino](practicas-arduino/) | Prácticas de clase (2023): LEDs, semáforos, botones con resistencias pull-up y pull-down, servomotor y una sirena con buzzer. |
| [Sensor de luz VEML7700](pantallas-lcd-oled/) | Prueba del sensor de luz VEML7700: mide la iluminación en lux por I2C (2025). |
| [Dibujo técnico en AutoCAD](autocad-dibujo-tecnico/) | Planos 2D del proyecto final de dibujo técnico (noviembre de 2022): engranes, aspas, piezas y vistas del ensamble, cada uno con su PDF. |
| [Piezas en SolidWorks](solidworks-piezas/) | Piezas modeladas en SolidWorks (capturas y planos, noviembre de 2022). |
| [Torno CNC](cnc-torno-winunisoft/) | Programas en código G (ISO) para torno CNC, simulados en WinUnisoft MultiCNC (octubre de 2023). |
| [Neumática e hidráulica](fluidsim-neumatica-hidraulica/) | Circuitos neumáticos, electroneumáticos e hidráulicos diseñados y simulados en FluidSIM (2022), con sus reportes. |
| [Electrónica básica](livewire-circuitos-electronicos/) | Simulaciones de electrónica básica en Livewire (2022): fuente de poder, 555 astable y monoestable, contadores, puente H y luces secuenciales. |
| [Circuitos en Proteus](proteus-circuitos-electronicos/) | Circuitos analógicos y digitales simulados en Proteus (2023-2024): control de motor con 555, circuitos de protección, sensor de temperatura LM35, leyes de Kirchhoff, análisis de circuitos y el convertidor ADC0804. |
| [Control eléctrico](cade-simu-control-electrico/) | Diagramas de control eléctrico (contactores, relevadores y motores) simulados en CADe_SIMU, con videos de la simulación. |
| [Simulación de robot industrial](robodk-simulacion/) | Animación de un robot industrial en RoboDK (octubre de 2023). |
| [Seleccionador de cajas](seleccionador-de-cajas/) | Proyecto en equipo: seleccionador automático de cajas (abril de 2024). |
| [Documentación técnica](documentacion-tecnica/) | Trabajos y reportes técnicos que no pertenecen a un proyecto específico, organizados por tema. |

## Habilidades

- **Programación de microcontroladores:** Arduino (C/C++), sensores ultrasónicos e infrarrojos, servomotores, motores DC y paso a paso, control PID, Bluetooth.
- **Electrónica:** diseño y simulación de circuitos (Proteus, Livewire, Fritzing), armado en protoboard y placa fenólica, diseño de PCB.
- **Neumática e hidráulica:** circuitos neumáticos, electroneumáticos e hidráulicos en FluidSIM.
- **Control eléctrico:** diagramas de contactores y relevadores en CADe_SIMU; PLC.
- **Manufactura:** programación de torno CNC en código G (WinUnisoft).
- **Dibujo y diseño:** AutoCAD, SolidWorks.
- **Robótica industrial:** RoboDK.

## Cómo abrir los archivos

| Extensión | Programa |
|---|---|
| `.ino` | Arduino IDE |
| `.pdsprj` | Proteus 8 |
| `.lvw` | Livewire |
| `.ct` | FluidSIM 4 |
| `.cad` | CADe_SIMU |
| `.fzz` | Fritzing |
| `.dwg` | AutoCAD (o cualquier visor DWG) |
| `.nc` | WinUnisoft / cualquier simulador de código G |
| `.rdk` | RoboDK |
| `.gbl` `.gtl` … | Visor Gerber (fabricación de PCB) |

## Estructura

Cada carpeta es un proyecto y contiene, según aplique: `codigo/` (la versión final; las anteriores están en `codigo/versiones/`), `simulaciones/`, `planos/`, `pcb/`, `documentos/` y `videos/`. Cada una tiene su propio README.
