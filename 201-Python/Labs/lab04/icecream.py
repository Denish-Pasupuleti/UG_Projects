if __name__ == "__main__":
    ice_cream_flavors = ["vanilla", "strawberry", "chocolate"]
    toppings = ["caramel", "marshmallow", "gummi bears"]
    for ice_cream in ice_cream_flavors:
        if ice_cream == "strawberry":
            print("strawberry is fine on its own")
        for topping in toppings:
            if ice_cream == "vanilla" or ice_cream == "chocolate":
                print(ice_cream + " is tasty with " + topping)
