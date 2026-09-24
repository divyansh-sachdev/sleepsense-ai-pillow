<div align="center">

# SleepSense AI Pillow

**Contactless sleep posture and snoring analysis from a pressure-sensor array**

![Domain](https://img.shields.io/badge/Domain-Pressure_Array_Classification-00F3FF?style=for-the-badge) ![Platform](https://img.shields.io/badge/Platform-ESP32_Edge-9D00FF?style=for-the-badge) ![Sensing](https://img.shields.io/badge/Sensing-Contactless-0066FF?style=for-the-badge)

![ESP32](https://img.shields.io/badge/ESP32-0D1117?style=flat-square&logo=espressif&logoColor=white) ![Arduino](https://img.shields.io/badge/Arduino-0D1117?style=flat-square&logo=arduino&logoColor=white) ![C++](https://img.shields.io/badge/C++-0D1117?style=flat-square&logo=cplusplus&logoColor=white) ![FSR_Array](https://img.shields.io/badge/FSR_Array-0D1117?style=flat-square) ![Acoustic](https://img.shields.io/badge/Acoustic-0D1117?style=flat-square)

</div>

---

## Overview

A sleep monitor embedded into a pillow rather than worn on the body. A three-zone force-sensitive
resistor array tracks head position through the night while an electret microphone captures snoring,
so posture and airway obstruction can be correlated without a wearable, a strap or a facial mask.

The clinically interesting relationship is between the two: supine (back) sleeping is strongly
associated with airway obstruction, so time-in-supine correlated against snore events is a far more
useful output than either signal alone.

## Domain &amp; Techniques

| Layer | Implementation |
| :--- | :--- |
| **Pressure Sensing** | Three FSR zones (left / centre / right) sampled on separate ADC channels |
| **Occupancy Gating** | Combined pressure below a floor value classifies the pillow as unoccupied, so an empty bed never generates posture data |
| **Posture Classification** | Ratio comparison between zones — a dominant centre zone (&gt;1.5&times; both sides) indicates supine, a dominant side zone (&gt;1.4&times; the other) indicates lateral, anything else is prone |
| **Snore Detection** | Band-limited electret microphone filtering isolates the low-frequency resonance characteristic of airway obstruction |
| **Correlation** | Supine duration is cross-referenced against snore events to grade severity |

## Pipeline

```
FSR left ---+
FSR centre -+--> total pressure --[ < floor ]--> ABSENT
FSR right --+          |
                       v
            ratio comparison between zones
                       |
        +--------------+---------------+
        |              |               |
   centre dominant  side dominant   neither
        |              |               |
      SUPINE      LEFT / RIGHT       PRONE
        |
        +--> correlated with --> electret mic --> snore events --> severity grade
```

## Hardware Connections

| Sensor | Pin | Function |
| --- | --- | --- |
| FSR Left Zone   | GPIO 34 | Left lateral pressure |
| FSR Center Zone | GPIO 35 | Supine head pressure |
| FSR Right Zone  | GPIO 39 | Right lateral pressure |
| Electret Mic    | GPIO 36 | Acoustic snore capture |

## Applications

- Sleep quality research and competition demonstrations
- Positional-therapy feedback for snoring
- Non-invasive monitoring where a wearable is impractical

## Repository Layout

| Path | Purpose |
| :--- | :--- |
| `SleepSensePillow.ino` | Main firmware — FSR sampling, acoustic capture, session logging |
| `posture_model.h` | `classifyPosture()` — occupancy gate and zone-ratio classification |
| `config.example.h` | Zone thresholds — copy to `config.h` |

## Project Status

**Implemented:** three-zone pressure acquisition, occupancy gating, deterministic posture
classification, acoustic snore capture.

**Roadmap:** the posture classifier uses fixed ratio thresholds tuned by hand; collecting labelled
overnight sessions would allow fitting those boundaries per user, since head weight and pillow
firmness shift the ratios significantly. Adding sleep-stage segmentation from movement frequency is
the follow-on.

> Research prototype, not a diagnostic device. Suspected sleep apnoea requires clinical polysomnography.

---

<div align="center">
  <sub>
    Part of the <b>AI + Robotics</b> engineering portfolio of
    <a href="https://github.com/divyansh-sachdev">Divyansh Sachdev</a><br>
    90+ national &amp; international competition wins &middot; IIT / NIT / IIIT podiums
  </sub>
</div>
