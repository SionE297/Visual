class Paper:
    def __init__(self, color, size):
        self.color = color
        self.size = size

    def display_size(self):
        print(self.size)

    def display_color(self):
        print(self.color)


sheet = Paper('white', 'A4')
sheet.display_size()
sheet.display_color()
