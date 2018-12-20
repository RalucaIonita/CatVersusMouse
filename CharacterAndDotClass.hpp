#include "MiscellaneousFunctions.hpp"
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
      
      Dot operator=(const Dot& dot)
      {
        x = dot.getDotX();
        y = dot.getDotY();
        return *this;
      }
      
      ~Dot()
      {}


      //set LED state for the dot
      void setDot(int k)
      {
        ledMatrix.setLed(0, y, x, k);
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
	}
  
	~Character()
	{}

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


  Character operator=(const Character& character)
  {
    head = character.getHead();
    tail = character.getTail();
   // return this;
  }


 
  
 //set LEDs' states for the character
 void setCharacter(int k)
 {
    head.setDot(k);
    tail.setDot(k);
 }

  
	//move
	Character moveMouse(int xJoystickValue, int yJoystickValue)
	{
    setCharacter(LOW);
    unsigned long timeNow = millis();
    //ox
		if(xJoystickValue > 550)
		{
      //head
	    if(head.getDotX() != 0)
         head.setDotX(head.getDotX() - 1);
        else
         head.setDotX(7);

      //tail
      if(tail.getDotX() != 0)
         tail.setDotX(tail.getDotX() - 1);
        else
         tail.setDotX(7);
      
		}
     
	 if(xJoystickValue < 450)
		  {
        //head
		    if(head.getDotX() != 7) 
          head.setDotX(head.getDotX() + 1);
        else
          head.setDotX(0);                                                                        ///////////////////SPACING IN THIS CRAP
         
         //tail
        if(tail.getDotX() != 7)
          tail.setDotX(tail.getDotX() + 1);
        else
          tail.setDotX(0);
		   }

		//oy
		if(yJoystickValue > 550)
		{
      //head
		  if(head.getDotY() != 0)
        head.setDotY(head.getDotY() - 1);
      else
        head.setDotY(7);
      
      //tail
      if(tail.getDotY() != 0)
        tail.setDotY(tail.getDotY() - 1);
      else
        tail.setDotY(7);
		}
   
		if(yJoystickValue < 450)
		{
      //head
		  if(head.getDotY() != 7)
		     head.setDotY(head.getDotY() + 1);
      else
         head.setDotY(0);

      //tail
     if(tail.getDotY() != 7)
         tail.setDotY(tail.getDotY() + 1);
      else
         tail.setDotY(0);
    }
    setCharacter(HIGH);
	} 



  
  void moveCat(Character mouse)
  {
    setCharacter(LOW);
    
    //oy
    if(mouse.getHead().getDotY() <= head.getDotY() && tail.getDotY()!=0)
    {
     head.setDotY(head.getDotY()-1);
     tail.setDotY(tail.getDotY()-1);
    }

    if(mouse.getHead().getDotY() > head.getDotY() && tail.getDotY()!=7)
    {
     head.setDotY(head.getDotY()+1);
     tail.setDotY(tail.getDotY()+1);
    }
    

    //ox
    if(mouse.getHead().getDotX() <= tail.getDotX())
    {
     head.setDotX(head.getDotX()-1);
     tail.setDotX(tail.getDotX()-1);
    }
    
    if(mouse.getHead().getDotX() > tail.getDotX())
    {
     head.setDotX(head.getDotX()+1);
     tail.setDotX(tail.getDotX()+1);
    }
    
  setCharacter(HIGH);
  }
  
};
