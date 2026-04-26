// --- Assignation des composants aux broches (Pins) ---
int led = 8;     // La LED est connectée à la broche 8
int btn = 9;     // Le bouton est sur la broche 9
int buzzer = 10; // Le buzzer est sur la broche 10

void setup() {
  // Configure la broche 8 en sortie pour piloter la LED
  pinMode(led, OUTPUT);
  
  // Configure la broche 9 en entrée avec la résistance de Pull-up interne active.
  // Cela évite les signaux "flottants" et simplifie le câblage (pas besoin de résistance externe).
  pinMode(btn, INPUT_PULLUP);
  
  // Configure la broche 10 en sortie pour le signal sonore
  pinMode(buzzer, OUTPUT);
}

void loop() {
  // Avec INPUT_PULLUP, le bouton est au repos à l'état HIGH (1).
  // Si on appuie dessus, le circuit se ferme vers la masse (GND) et passe à LOW (0).
  if (digitalRead(btn) == LOW) { 
    
    // Action si le bouton est pressé :
    digitalWrite(led, HIGH);   // Allume la LED
    tone(buzzer, 1000);        // Active le buzzer à une fréquence de 1000Hz (Bip aigu)
    
  } else {
    
    // Action si le bouton est relâché :
    digitalWrite(led, LOW);    // Éteint la LED
    noTone(buzzer);            // Arrête le son du buzzer
    
  }
}