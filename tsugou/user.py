class User:
    def __init__(self, name, timezone, contacts):
        self.name = name
        self.timezone = timezone
        self.contacts = contacts

    def __str__(self):
        return self.__dict__.__str__()
    
