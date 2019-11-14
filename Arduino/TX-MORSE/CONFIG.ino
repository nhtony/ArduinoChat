
const int tonefreq = 523; // tone frequency C

const int dotlength = 100; // constants for tone and rest durations

const int dashlength = dotlength * 3;// inter-element gap - between each dot or dash of a letter

const int inter = dotlength; // letter gap is 3 dots - the inter gap is always added - so this is one fewer

const int lgap = dotlength * 2; // inter-letter gap

// word gap is 7 dots - with letter and inter gap already counted, this is -1
const int wgap = dotlength * 4; //inter-word gap
