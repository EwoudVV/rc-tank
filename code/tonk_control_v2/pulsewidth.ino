void setupReceiver() {
  DEBUG_PRINTLN("INFO: Setting up Frsky receiver inputs ...");
  pinMode(LEFT_CHANNEL_PIN, INPUT);
  pinMode(RIGHT_CHANNEL_PIN, INPUT);
}


void printPulsewidths() {
  DEBUG_PRINT("leftPW: ");
  DEBUG_PRINT(leftPulsewidth);
  DEBUG_PRINT(" | ");
  DEBUG_PRINT("rightPW: ");
  DEBUG_PRINTLN(rightPulsewidth);
}