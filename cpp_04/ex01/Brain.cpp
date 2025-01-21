#include "Brain.hpp"

Brain::Brain()
{
    std::cout << "Brain constructor called" << std::endl;
	ideas[0] = "Every moment spent with my human is pure happiness." ;
	ideas[1] = "I wonder if my human knows how much I love them.";
	ideas[2] = "Why do they always leave me alone?";
	ideas[3] = "That squirrel outside looks so tasty!";
	ideas[4] = "I wish I could talk to other dogs.";
	ideas[5] = "Where did that toy go? I need it now!";
	ideas[6] = "I hope my human brings home a treat today.";
	ideas[7] = "Why do they call it 'bath time'? It should be 'torture time'.";
	ideas[8] = "I just want to chase my tail one more time.";
	ideas[9] = "This couch is my throne!";
	ideas[10] = "I can smell dinner cooking. Is it for me?";
	ideas[11] = "Why do humans get to eat from plates?";
	ideas[12] = "I love when my human scratches behind my ears.";
	ideas[13] = "If I bark loud enough, maybe they'll let me outside.";
	ideas[14] = "I think I could catch that frisbee if I just try harder.";
	ideas[15] = "Every time the doorbell rings, it's like a party!";
	ideas[16] = "What if my human is actually a superhero?";
	ideas[17] = "I wish I could understand what they're saying.";
	ideas[18] = "Why do they put me in this crate sometimes?";
	ideas[19] = "I hope there's a dog park in heaven.";
	ideas[20] = "Can we go for a car ride? Please?";
	ideas[21] = "I'm pretty sure I'm the best guard dog ever.";
	ideas[22] = "Why do humans have to wear shoes all the time?";
	ideas[23] = "I love playing fetch, but why don't they ever fetch back?";
	ideas[24] = "If only I could have a steak every day!";
	ideas[25] = "I feel like I'm part of the family, even if I'm just a dog.";
	ideas[26] = "Why is the box on the table making noise? Is it alive?";
	ideas[27] = "That sunbeam is my favorite spot in the house.";
	ideas[28] = "Can I have some of that ice cream too?";
	ideas[29] = "What do they mean by 'cat nap'? Aren't all naps for cats?";
	ideas[30] = "I wonder what birds think about all day.";
	ideas[31] = "This scratch post is my personal gym.";
	ideas[32] = "Why do they keep moving that red dot around?";
	ideas[33] = "Is it wrong to knock things off the table? It’s so fun!";
	ideas[34] = "I think my human needs more cuddles.";
	ideas[35] = "Why do they always call me when I'm napping?";
	ideas[36] = "That new cat in the neighborhood looks suspicious.";
	ideas[37] = "I could watch the fish tank all day long.";
	ideas[38] = "Do humans know how to purr? They should try it!";
	ideas[39] = "Why does my human laugh when I chase my tail?";
	ideas[40] = "If only I could climb trees like those squirrels.";
	ideas[41] = "What’s with all these boxes? Are they hiding something?";
	ideas[42] = "I think I’m secretly a lion in disguise.";
	ideas[43] = "Can we please play with that string again?";
	ideas[44] = "Why does everyone think cats are aloof? I'm just busy!";
	ideas[45] = "That vacuum cleaner is definitely out to get me.";
	ideas[46] = "Is there a reason why humans leave their food unattended?";
	ideas[47] = "I love when my human sings; it makes me feel special.";
	ideas[48] = "What if I could talk? What would I say first?";
	ideas[49] = "Every time I see a mirror, I wonder who that other cat is.";
	ideas[50] = "Sometimes I wish I could fly like a bird.";
	ideas[51] = "Why does my human get mad when I scratch the furniture?";
	ideas[52] = "That cardboard box looks like the perfect hideout.";
	ideas[53] = "If only I had thumbs, I'd open all the treats myself!";
	ideas[54] = "What if every day was a holiday filled with snacks?";
	ideas[55] = "Do humans know how to nap properly? They should take notes from us!";
	ideas[56] = "Sometimes, I just want to sit on top of my human's keyboard.";
	ideas[57] = "Is there such a thing as too many toys?";
	ideas[58] = "Why do humans insist on taking pictures of me while Im sleeping?";
	ideas[59] = "The best part of the day is when my human comes home.";
	ideas[60] = "Do other cats dream about catching mice too?";
	ideas[61] = "If only I could understand why humans love baths.";
	ideas[62] = "That sound from outside makes me curious. What is it?";
	ideas[63] = "Do humans realize how much fun it is to chase shadows?";
	ideas[64] = "Sometimes, I think I'm part of a reality show.";
	ideas[65]= "Whats so exciting about going outside? There are so many smells!";
	ideas[66]= "If only every meal was fish-flavored.";
	ideas[67]= "Can we have a family meeting about treats?";
	ideas[68]= "Why do humans always want to pet me when Im busy?";
	ideas[69]= "My favorite game is hide and seek—Im really good at hiding!";
	ideas[70]= "What if every cat had their own personal chef?";
	ideas[71]= "Is there an award for being the cutest pet?";
	ideas[72]= "Sometimes, I feel like Im royalty in this house.";
	ideas[73]= "Do you think other pets have secret lives too?";
	ideas[74]= "If only I could eat tuna every day!";
	ideas[75]= "Whats with that strange thing called exercise?";
	ideas[76]= "I wonder if my human knows how much joy they bring me.";
	ideas[77]= "Can we have more playdates with other pets?";
	ideas[78]= "Is there such a thing as too many naps?";
	ideas[79]= "Whats that weird smell coming from the fridge?";
	ideas[80]= "Sometimes, I wish I could go on adventures with my human.";
 	ideas[81]="How come humans never share their snacks with us?"; 
 	ideas[82]="Is there a secret cat society out there?"; 
 	ideas[83]="I think Id make an excellent detective!"; 
 	ideas[84]="What if all those toys are actually alive?"; 
 	ideas[85]="Can we please have more cuddle sessions?"; 
 	ideas[86]="Why does everyone laugh when I trip over my own paws?"; 
 	ideas[87]="Do humans know how to enjoy life like we do?"; 
 	ideas[88]="If only every day was filled with sunshine and treats!"; 
 	ideas[89]="What’s that noise? Is it snack time already?"; 
 	ideas[90]="Sometimes, I feel like I am on top of the world!";
 	ideas[91]="If only every meal was made just for me!"; 
 	ideas[92]="Do you think other pets dream about us too?"; 
 	ideas[93]="How come humans get to stay up late and we don’t?"; 
 	ideas[94]="Is there such a thing as too many toys?"; 
 	ideas[95]="Sometimes, I wonder if we are all part of a big family."; 
 	ideas[96]="Can we have more outdoor adventures together?"; 
 	ideas[97]="What if every pet had their own theme song?"; 
 	ideas[98]="Do you think pets understand each others languages?"; 
 	ideas[99]="Is there an award for being the best cuddle buddy?";
}

Brain::Brain(const Brain &a)
{
    std::cout << "Brain copy constructor called" << std::endl;
    for (int i = 0; i < 100; i++)
        this->ideas[i] = a.ideas[i];
}

Brain &Brain::operator=(const Brain &a)
{
	std::cout << "Brain assignment constructor called" << std::endl;
    if (this != &a)
    {
        for (int i = 0; i < 100; i++)
            this->ideas[i] = a.ideas[i];
    }
    return (*this);
}

Brain::~Brain()
{
    std::cout << "Brain destructor called" << std::endl;
}
