hero_villain = input("Are you a hero or a villain? ")
if hero_villain == "villain":
    name_villain = input("What is your name? ")
    print(name_villain + " Sounds pretty evil!")
elif hero_villain == "hero":
    people_saved = int( input("How many people have you saved? "))
    if people_saved <= 10:
        print("Go on more patrols!")
    if people_saved > 10 and people_saved < 100:
        print("Sounds like you're making a difference!")
    if people_saved > 100:
        print("Wow, great job saving the city")
        
