# Desafio Semana 01: Estação Meteorológica com ESP32 e Firebase

Este projeto faz parte do "CursoMakerIFSULDEMINAS-EXT" e implementa uma estação meteorológica básica utilizando um microcontrolador ESP32. Ele coleta dados de temperatura, umidade e luminosidade, e os envia para um banco de dados Firebase em tempo real.

## Funcionalidades

-   **Leitura de Temperatura e Umidade:** Utiliza o sensor DHT22 para obter dados precisos de temperatura em graus Celsius e umidade relativa.
-   **Leitura de Luminosidade:** Mede a intensidade luminosa ambiente através de um LDR (Light Dependent Resistor), convertendo o valor analógico em lux.
-   **Conectividade Wi-Fi:** O ESP32 se conecta a uma rede Wi-Fi para acesso à internet.
-   **Envio de Dados para Firebase:** Os dados coletados são formatados em JSON e enviados via HTTP PUT para um endpoint específico no Firebase Realtime Database.
-   **Indicador Visual:** Um LED azul pisca para indicar que o programa está em execução (embora a lógica atual o mantenha aceso).

## Hardware Necessário

-   **ESP32 Development Board:** Placa principal para o projeto.
-   **Sensor DHT22:** Para medição de temperatura e umidade.
-   **LDR (Photoresistor):** Para medição de luminosidade.
-   **Resistor de 10kΩ:** Utilizado no divisor de tensão para o LDR.
-   **LED Azul:** Para indicação visual.
-   **Resistor para o LED:** (Opcional, mas recomendado para proteger o LED, geralmente 220Ω ou 330Ω).
-   **Jumpers:** Fios para as conexões.
-   **Protoboard:** (Opcional) Para montar o circuito.

## Software Necessário

-   **Arduino IDE:** Ambiente de desenvolvimento.
-   **Pacote de Placas ESP32:** Instalado no Arduino IDE (via Boards Manager).
-   **Bibliotecas:**
    -   `DHT.h`: Para interface com o sensor DHT22.
    -   `WiFi.h`: Para gerenciamento da conexão Wi-Fi do ESP32.
    -   `HTTPClient.h`: Para fazer requisições HTTP (envio de dados para Firebase).

## Configuração e Uso

1.  **Instale o Pacote de Placas ESP32:**
    -   No Arduino IDE, vá em `Arquivo > Preferências`.
    -   Adicione `https://raw.githubusercontent.com/espressif/arduino-esp32/gh-pages/package_esp32_index.json` nas "URLs Adicionais para Gerenciadores de Placas".
    -   Vá em `Ferramentas > Placa > Gerenciador de Placas...` e procure por "esp32" para instalar o pacote.

2.  **Instale as Bibliotecas:**
    -   No Arduino IDE, vá em `Sketch > Incluir Biblioteca > Gerenciar Bibliotecas...`.
    -   Procure por "DHT sensor library" (de Adafruit) e instale-a.
    -   As bibliotecas `WiFi.h` e `HTTPClient.h` geralmente vêm pré-instaladas com o pacote ESP32.

3.  **Configure as Credenciais Wi-Fi e Firebase:**
    -   Abra o arquivo `sketch.ino`.
    -   Altere as variáveis `ssid` e `password` para as credenciais da sua rede Wi-Fi:
        ```cpp
        const char* ssid = "SEU_SSID";
        const char* password = "SUA_SENHA";
        ```
    -   Altere a variável `firebaseUrl` para o URL do seu projeto Firebase Realtime Database:
        ```cpp
        String firebaseUrl = "https://SEU-PROJETO-ID-default-rtdb.firebaseio.com/";
        ```

4.  **Carregue o Código:**
    -   Conecte seu ESP32 ao computador.
    -   Selecione a placa e a porta serial corretas em `Ferramentas > Placa` e `Ferramentas > Porta`.
    -   Clique em "Carregar" (Upload) para enviar o código para o ESP32.

## Funcionamento

Após o upload, o ESP32 se conectará ao Wi-Fi. No loop principal, ele lerá a temperatura e umidade do DHT22, o valor analógico do LDR (convertendo-o para lux), e então enviará esses três valores para o Firebase. O LED azul piscará (ou permanecerá aceso, dependendo da correção da lógica de piscar) a cada ciclo. Os dados enviados para o Firebase serão armazenados sob o nó `/estacao1.json`.
