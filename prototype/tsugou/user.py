class User:
    def __init__(self, id, name, timezone, contacts):
        self.id = id
        self.name = name
        self.timezone = timezone
        self.contacts = contacts

    def __str__(self):
        return self.__dict__.__str__()
    
