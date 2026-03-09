# brake-ligth

## Descripción

Crear un sistema de luz LED que se active por desaceleración (frenado) utilizando un acelerómetro y Arduino es un proyecto clásico y útil para seguridad, por ejemplo, en bicicletas o vehículos pequeños. El sensor más común para esto es el MPU6050 debido a su bajo costo, alta precisión y comunicación I2C.

### Objetivo del Proyecto

Este proyecto implementa un sistema inteligente de frenado automático que detecta la desaceleración del vehículo o bicicleta mediante un acelerómetro de 6 ejes (aceleración + giroscopio) y activa automáticamente una luz LED roja de alerta. Es especialmente útil para aumentar la visibilidad y seguridad en entornos urbanos o rurales, alertando a otros usuarios viales sobre el frenado.

### ¿Por qué el MPU6050?

- **Bajo costo**: Muy asequible en el mercado (módulos GY-521 de 2-5€)
- **Alta precisión**: Acelerómetro de ±16g y giroscopio de ±2000°/s
- **Comunicación I2C**: Requiere solo 2 cables de datos (SDA/SCL), ideal para Arduino
- **Amplio rango**: Detecta desde microgravedad hasta aceleraciones severas
- **Librería disponible**: Existen librerías bien documentadas como MPU6050 de Electronics Cats

### Aplicaciones Posibles

- 🚴 **Bicicletas**: Sistema de luz de frenado inteligente
- 🛴 **Patinetes eléctricos**: Alerta visual de desaceleración
- 🚗 **Vehículos pequeños**: Luces de freno auxiliares
- 🛵 **Motocicletas**: Sistema de seguridad adicional
- 🤖 **Robots móviles**: Detección de cambios de velocidad

### Ventajas del Sistema

✅ Automatización sin necesidad de interacción manual
✅ Respuesta inmediata (milisegundos)
✅ Bajo consumo de energía
✅ Fácil instalación y calibración
✅ Versátil: Puede usar LEDs individuales, tiras LED o incluso buzzer de alerta
✅ Escalable: Se puede integrar con sistemas más complejos

---

## Componentes Necesarios

- Arduino Uno/Nano.
- Sensor Acelerómetro MPU6050 (GY-521).
- LEDs (rojos preferiblemente).
- Resistencias (220-330 ohm para los LEDs).
- Cables puente y protoboard. 

## Conexión del MPU6050 a Arduino

El MPU6050 utiliza el protocolo I2C, lo que facilita la conexión: 

- VCC: 3.3V o 5V (la mayoría de módulos GY-521 tienen regulador).
- GND: GND del Arduino.
- SCL: Pin A5 (en Uno/Nano).
- SDA: Pin A4 (en Uno/Nano). 

## Concepto de Funcionamiento

- **Montaje**: Se debe montar el sensor de forma vertical (o calibrarlo) para detectar la desaceleración en el eje de avance (por ejemplo, el eje X o Y, dependiendo de cómo se coloque).
- **Detección**: La desaceleración se detecta cuando el valor de aceleración en el eje de movimiento disminuye por debajo de un umbral específico (o cambia de signo).
- **Acción**: Cuando el Arduino detecta una caída en la aceleración (frenado) mayor al umbral definido, activa la salida del LED. 

## Código Básico (Idea General)

Este código lee el eje X (asumiendo que es el eje de avance) y enciende un LED si la desaceleración es alta. 

## Consejos para el Proyecto

- **Calibración**: El valor de "cero" puede cambiar, por lo que es necesario calibrar el sensor una vez montado para establecer el umbral correcto.
- **Filtro**: Para evitar que la luz LED parpadee con baches, se puede promediar varias lecturas del acelerómetro o usar un filtro pasa-bajos.
- **Frenado fuerte**: El enfoque más simple es medir el cambio en un solo eje, pero para mayor precisión se puede usar la magnitud total del vector de aceleración.
- **Alternativa**: Si el proyecto es para una bicicleta, un microinterruptor en la palanca de freno puede ser más preciso que un acelerómetro.
