# SleepSense AI Pillow

Non-invasive smart sleep monitoring system embedded into pillows to monitor head kinematics, sleep posture, snoring events, and potential obstructive sleep apnea patterns without requiring wearables or facial masks.

## System Architecture

- **Force Sensitive Resistor (FSR) Array**: Multi-zone pressure grid tracks head position and movements throughout sleep cycles.
- **Acoustic Snore Detection**: Band-limited microphone filtering extracts resonant frequencies indicative of airway obstruction.
- **Local Heuristic Inference**: Classifies sleep posture (Supine, Lateral, Prone) and correlates supine duration with snoring severity.

## Hardware Connections

| Sensor | Pin | Function |
| --- | --- | --- |
| FSR Left Zone   | GPIO 34 | Left lateral pressure |
| FSR Center Zone | GPIO 35 | Supine head pressure |
| FSR Right Zone  | GPIO 39 | Right lateral pressure |
| Electret Mic    | GPIO 36 | Acoustic snore capture |

## Applications
- Sleep quality research & competition demos.
- Early detection of sleep stage disruptions.
