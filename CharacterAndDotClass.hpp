#include "Setup.hpp"

class Dot
  {
    private:
      int x, y;
    public:
      //getters & setters

      int getDotX()
      {
        return x;
      }

      int getDotY()
      {
        return y;
      }

      void setDotX(int xValue)
      {
        x=xValue;
      }

      void setDotY(int yValue)
      {
        y=yValue;
      }

      void setDotCoordinates(int xValue, int yValue)
      {
        x=xValue;
        y=yValue;
      }

      

      Dot()
      {}
      ~Dot()
      {}


      //set LED state for the dot
      void setDot(int k)
      {
        ledMatrix.setLed(0, y, x, k);
      }
      
      friend operator==(const Dot& firstDot, const Dot& secondDot)
      {
        if(firstDot.getDotX() == secondDot.getDotX() && firstDot.getDotY() == secondDot.getDotY())
          return 1;
        else
          return 0;      
      }
  };


class Character
{
private:
	Dot head, tail;
public:
  
	//constructor & destructor
  Character(){};
	Character(String characterName)
	{
		if(characterName == "mouse")
		{
			head.setDotCoordinates(0, 1);
			tail.setDotCoordinates(0, 0);
		}
		else
		{
		if(characterName=="cat")
		{
      head.setDotCoordinates(7, 7);
      tail.setDotCoordinates(7, 6);
     }
		}
	};

	~Character()
	{};

  //getters & setters
  Dot getHead()
  {
    return head;
  }

  Dot getTail()
  {
    return tail;
  }

  void setHead(Dot givenDot)
  {
    head.setDotX(givenDot.getDotX());
    head.setDotY(givenDot.getDotY());
  }

  void setTail(Dot givenDot)
  {
    tail.setDotCoordinates(givenDot.getDotX(), givenDot.getDotY());
  }
 
  
 //set LEDs' states for the character
 void setCharacter(int k)
 {
    head.setDot(k);
    tail.setDot(k);
 }

  
	//move
	Character moveCharacter(int xJoystickValue, int yJoystickValue)
	{
    setCharacter(LOW);
		if(xJoystickValue > 550 && head.getDotX() != 0)
			{
          head.setDotX(head.getDotX() - 1);
          tail.setDotX(tail.getDotX() - 1);
			}
		else
		{
		if(xJoystickValue < 450 && head.getDotX() != 7) 
			{
        head.setDotX(head.getDotX() + 1);
        tail.setDotX(tail.getDotX() + 1);
			}
		}

		
		if(yJoystickValue > 550 && head.getDotY() != 1)
			{
        head.setDotY(head.getDotY() - 1);
        tail.setDotY(tail.getDotY() - 1);
			}
		else
		{
		if(yJoystickValue < 450 && tail.getDotY() != 6)
			{
				head.setDotY(head.getDotY() + 1);
        tail.setDotY(tail.getDotY() + 1);
			}
		}
    setCharacter(HIGH);
   
	}
 
  //operator ==

  friend operator==(Character firstCharacter, Character secondCharacter)
  {
    if(firstCharacter.head == secondCharacter.head && firstCharacter.tail == secondCharacter.tail)
      return 1;
    else
      return 0;    
  }
  
  
  void moveCat(Character mouse)
  {
    setCharacter(LOW);
    
    //oy
    if(mouse.getHead().getDotY() <= head.getDotY() && head.getDotY() != 0)
    {
     head.setDotCoordinates(head.getDotX(), head.getDotY()-1);
     tail.setDotCoordinates(tail.getDotX(), tail.getDotY()-1);
    }

    if(mouse.getHead().getDotY() >= head.getDotY() && head.getDotY() != 7)
    {
     head.setDotCoordinates(head.getDotX(), head.getDotY()+1);
     tail.setDotCoordinates(tail.getDotX(), tail.getDotY()+1);
    }
    

    //ox
    if(mouse.getHead().getDotX() <= head.getDotX() && head.getDotX() != 0)
    {
     head.setDotCoordinates(head.getDotX()-1, head.getDotY());
     tail.setDotCoordinates(tail.getDotX()-1, tail.getDotY());
    }
    
    if(mouse.getHead().getDotX() >= head.getDotX() && head.getDotX() != 7)
    {
     head.setDotCoordinates(head.getDotX()+1, head.getDotY());
     tail.setDotCoordinates(tail.getDotX()+1, tail.getDotY());
    }
    
  setCharacter(HIGH);
  }
  
    
};
