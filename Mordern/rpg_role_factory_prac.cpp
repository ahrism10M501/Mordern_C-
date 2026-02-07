/*
	Factory Method 연습을 위해서 기획
	RPG Game의 직업군을 팩토리 메서드를 이용해 생성한다는 취지
	1. Character, 모든 캐릭터는 attack() 순수 가상 함수를 가짐
		Warrior
		Mage
		- 이후 Archer를 추가할 때 OOP가 유지되는가!
	2. Creator, 기반 클래스
		CreateCharacter(): 팩토리 함수
		play(): 팩토리로 캐릭터 생성 및 공격하게 하는 일반 함수
	3. Concrete Creator

	만들다 보니까 불만이 많아져서 이것저것 더 넣었다
	1. IGame 추가
		다른 함수에서 Game을 쓰려는데 템플릿 때문에 못 쓴다.
		그래서 IGame 인터페이스를 추가해 다형성으로 사용 가능하게 했다
	2. runGame() 추가
		클라이언트가 모든 게임을 동일하게 다룰 수 있게 한다.
		직접 하나하나 하는건 위험하므로 프로세스를 캡슐화했다
	3. hasCharacter() 추가
		attack 하려는데 캐릭터가 없으면 프로그램이 멈추니까, 안전장치를 만들었다
		짧은 함수라서 inline 선언해서 최적화를 진행했다

	팩토리 메서드 패턴은 새로운 직업군이 생길 때, 인터페이스 규칙만 잘 지키고
	클래스 몇 개만 추가하면 되므로 편리하다.
	특히, CRTP 형식으로 만들면 vtable 오버헤드도 없어진다

	다만, 코드 가독성은 떨어진다.
	
	클래스 이름을 잘못 설정해서 이해하기 어렵겠지만,
	나중에 프로그램을 확장해서 기능을 추가할 때는 다른 모든 것들이 runGame 함수처럼
	IGame만 알면 되므로 이후 유지보수가 편리하다.

	만약 팩토리가 아니었다면, 클라이언트가 직접 Warrior, Mage, Archer를 if-else문으로
	구분해야 했을 것이다.

	기능을 추가할 때는, 각 캐릭터 클래스의 인스턴스를 추가하면 된다.
	문제는, 만약 Warrior에는 Shout가 추가되는데, Mage에는 없으면
	프로그램이 중지된다.

	따라서, Skill 과 같은 것들은 차후 인터페이스로 분리해 좀 더 다이나믹하게 구현하자

	그때는 Strategy 패턴이 요긴하다!
*/

#include <iostream>
#include <memory>
#include <string>
#include <cstring>

class Character {
	std::string name;
public:
	Character(std::string n) : name(std::move(n)) {}
	virtual ~Character() = default;
	virtual void attack() = 0;

	std::string getName() const { return name; }
};

class Warrior : public Character {
public:	
	using Character::Character;
	void attack() override {
		std::cout << "Warrior "<< getName() <<"'s Attack!\n";
	}
};

class Mage : public Character {
public:
	using Character::Character;
	void attack() override {
		std::cout << "Mage "<< getName() << "'s Attack!\n";
	}
};

class Archer : public Character {
public:
	using Character::Character;
	void attack() override {
		std::cout << "Archer " << getName() << "'s Attack!\n";
	}
};

class IGame {
public:
	virtual ~IGame() = default;
	virtual void create(const std::string& name) = 0;
	virtual void play() = 0;
};

template<typename Derived>
class Game : public IGame {
	std::unique_ptr<Character> character;

public:
	virtual ~Game() = default;

	void create(const std::string& name) override {
		character = static_cast<Derived*>(this)->createCharacter(name);
	}

	inline bool hasCharacter() const {
		return character != nullptr;
	}

	void play() override {
		if (hasCharacter()) {
			character->attack();
		}
		else {
			std::cout << "Make character before playing gamge\n";
		}
	}
};

class WarriorGame : public Game<WarriorGame> {
public:
	std::unique_ptr<Character> createCharacter(const std::string& name) {
		return std::make_unique<Warrior>(name);
	}
};

class MageGame : public Game<MageGame> {
public:
	std::unique_ptr<Character> createCharacter(const std::string& name) {
		return std::make_unique<Mage>(name);
	}
};

class ArcherGame : public Game<ArcherGame> {
public:
	std::unique_ptr<Character> createCharacter(const std::string& name) {
		return std::make_unique<Archer>(name);
	}
};

void runGame(IGame* game, const std::string& name) {
	game->create(name);
	game->play();
}

/*
int main() {
	WarriorGame wGame;
	wGame.create("Conan");
	wGame.play();

	MageGame mGame;
	mGame.create("Gandalf");
	mGame.play();

	ArcherGame aGame;
	runGame(&aGame, std::string("Legolas"));

	return 0;
}
*/