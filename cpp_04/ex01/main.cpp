#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

#define BLUE_BOLD	"\033[34;1;4m"
#define RESET		"\033[0m"

int main()
{
	{
		std::cout << BLUE_BOLD"Tests begin"RESET << std::endl;
		int test_cnt = 20;
		Animal* animal_arr[test_cnt];

		std::cout << std::endl << BLUE_BOLD"Creating array of Cats and Dogs"RESET << std::endl;
		for (int i = 0; i < test_cnt; i++)
		{
			if (i % 2 == 0)
				animal_arr[i] = new Dog();
			else
				animal_arr[i] = new Cat();
		}

		std::cout << std::endl << BLUE_BOLD"Checking animal types and forsing them to make sound"RESET << std::endl;
		for (int i = 0; i < test_cnt; i++)
		{
			std::cout << "This is a " << animal_arr[i]->getType() << std::endl;
			animal_arr[i]->makeSound();
		}

		std::cout << std::endl << BLUE_BOLD"Deleting animals"RESET << std::endl;
		for (int i = 0; i < test_cnt; i++)
		{
			delete animal_arr[i];
			std::cout << std::endl;
		}
	}
	{
		std::cout << std::endl << BLUE_BOLD"Deep Copy Test Cat Copy"RESET << std::endl;
		Cat cat;
		Cat copy_cat(cat);
		std::cout << "42nd idea from Cat cat: " << cat.getIdea(42) << std::endl;
		cat.setIdea(42, "Maybe I need to go to piscine 42...");
		std::cout << "42nd new idea from Cat cat: " << cat.getIdea(42) << std::endl;
		std::cout << "42nd idea from Cat copy_cat: " << copy_cat.getIdea(42) << std::endl;
	}
	{
		std::cout << std::endl << BLUE_BOLD"Deep Copy Test Cat Assignment"RESET << std::endl;
		Cat cat;
		Cat assignment_cat(cat);
		
		std::cout << "42nd idea from Cat cat: " << cat.getIdea(42) << std::endl;
		cat.setIdea(42, "I will definetely go to piscine!");
		std::cout << "42nd new idea from Cat cat: " << cat.getIdea(42) << std::endl;
		std::cout << "42nd idea from Cat assignment_cat before assignment: " << assignment_cat.getIdea(42) << std::endl;
		assignment_cat = cat;
		std::cout << "42nd idea from Cat assignment_cat after assignment: " << assignment_cat.getIdea(42) << std::endl;
		assignment_cat.setIdea(42, "I will never go to piscine. Im afraid of water");
		std::cout << "42nd new idea from Cat assignment_cat: " << assignment_cat.getIdea(42) << std::endl;
		std::cout << "42nd idea from Cat cat: " << cat.getIdea(42) << std::endl;
	}	
	{
		std::cout << std::endl << BLUE_BOLD"Deep Copy Test Dog Copy"RESET << std::endl;
		Dog dog;
		Dog copy_dog(dog);
		std::cout << "42nd idea from Dog dog: " << dog.getIdea(42) << std::endl;
		dog.setIdea(42, "No piscine, just bark bark");
		std::cout << "42nd new idea from Dog dog: " << dog.getIdea(42) << std::endl;
		std::cout << "42nd idea from Dog copy_dog: " << copy_dog.getIdea(42) << std::endl;
	}
	{
		std::cout << std::endl << BLUE_BOLD"Deep Copy Test Dog Assignment"RESET << std::endl;
		Dog dog;
		Dog assignment_dog(dog);
		
		std::cout << "42nd idea from Dog dog: " << dog.getIdea(42) << std::endl;
		dog.setIdea(42, "Maybe I need to go to piscine 42...Cat's can't be wrong!");
		std::cout << "42nd new idea from Dog dog: " << dog.getIdea(42) << std::endl;
		std::cout << "42nd idea from Dog assignment_dog before assignment: " << assignment_dog.getIdea(42) << std::endl;
		assignment_dog = dog;
		std::cout << "42nd idea from Dog assignment_dog after assignment: " << assignment_dog.getIdea(42) << std::endl;
		assignment_dog.setIdea(42, "I will definetely handle passing the piscine! Dogs are good at swimming!");
		std::cout << "42nd new idea from Dog assignment_dog: " << assignment_dog.getIdea(42) << std::endl;
		std::cout << "42nd idea from Dog dog: " << dog.getIdea(42) << std::endl;
	}

	return 0;
}
