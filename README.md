# Curso Maker IFSULDEMINAS - Extensão

Projeto de extensão do **Curso Maker** do IFSULDEMINAS — Estação Meteorológica com ESP32, sensores e integração com Firebase.

## Conteúdo do Repositório

| Item | Descrição |
|------|-----------|
| `sketch.ino` | Código principal (ESP32 + DHT22 + Firebase) |
| `LendoServidorAula2.json` | Diagrama de montagem Wokwi |
| `libraries.txt` | Dependências de bibliotecas para simulação |
| `DesafioSemana01/` | Versão expandida com LDR (luminosidade) |

## Funcionalidades

- Leitura de **temperatura e umidade** (DHT22)
- Leitura de **luminosidade** (LDR) — na versão do desafio
- Envio de dados para **Firebase Realtime Database** via HTTP PUT
- Simulação no **Wokwi** (plataforma online de IoT)

## Hardware

- ESP32 DevKit v4
- Sensor DHT22
- LDR + resistor 10kΩ
- LEDs (indicadores)

## Como Usar

1. Abra o diagrama `LendoServidorAula2.json` no [Wokwi](https://wokwi.com)
2. Edite as credenciais Wi-Fi e a URL do Firebase no `sketch.ino`
3. Execute a simulação ou carregue em um ESP32 físico

## Firebase

Os dados são enviados para o nó `/estacao1.json` no formato:

```json
{
  "temperatura": 23.5,
  "umidade": 71.5,
  "luminosidade": 450.2,
  "uptime": 123456
}
```

## Licença

Projeto educacional — IFSULDEMINAS.
