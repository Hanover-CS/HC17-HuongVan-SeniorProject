/*
 * tonePlay function that takes two arguments of int. First one determines the sound, and the second parameter determines frequency of chosen sound.
 * then it will call the bult-in tone with the arguments passed.
 * the sound will last for 1s by calling buil-int delay with approriate value.
 */
void tonePlay(int sound1, int frequency) {
   tone(5, sound1, frequency);
   delay(10);
}
