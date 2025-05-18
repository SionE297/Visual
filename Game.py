import pygame
import random

# Initialize Pygame
pygame.init()

# Constants
SCREEN_WIDTH = 800
SCREEN_HEIGHT = 600
WHITE = (255, 255, 255)
BLACK = (0, 0, 0)
RED = (255, 0, 0)
BASKET_WIDTH = 100
BASKET_HEIGHT = 20
BASKET_SPEED = 10
OBJECT_WIDTH = 20
OBJECT_HEIGHT = 20
OBJECT_FALL_SPEED = 7

# Create the screen
screen = pygame.display.set_mode((SCREEN_WIDTH, SCREEN_HEIGHT))
pygame.display.set_caption("Catch the Falling Object")

# Basket (Player) class
class Basket:
    def __init__(self):
        self.rect = pygame.Rect((SCREEN_WIDTH // 2, SCREEN_HEIGHT - BASKET_HEIGHT), (BASKET_WIDTH, BASKET_HEIGHT))

    def move(self, dx):
        self.rect.x += dx
        if self.rect.x < 0:
            self.rect.x = 0
        elif self.rect.x > SCREEN_WIDTH - BASKET_WIDTH:
            self.rect.x = SCREEN_WIDTH - BASKET_WIDTH

    def draw(self, screen):
        pygame.draw.rect(screen, BLACK, self.rect)

# Falling Object class
class FallingObject:
    def __init__(self):
        self.rect = pygame.Rect(random.randint(0, SCREEN_WIDTH - OBJECT_WIDTH), 0, OBJECT_WIDTH, OBJECT_HEIGHT)

    def fall(self):
        self.rect.y += OBJECT_FALL_SPEED

    def draw(self, screen):
        pygame.draw.rect(screen, RED, self.rect)

    def off_screen(self):
        return self.rect.y > SCREEN_HEIGHT

# Game loop
def game_loop():
    basket = Basket()
    objects = []
    clock = pygame.time.Clock()
    score = -10

    running = True
    while running:
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                running = False

        keys = pygame.key.get_pressed()
        if keys[pygame.K_LEFT]:
            basket.move(-BASKET_SPEED)
        if keys[pygame.K_RIGHT]:
            basket.move(BASKET_SPEED)

        # Add a new object
        if random.randint(1, 30) == 1:
            objects.append(FallingObject())

        # Move and remove objects
        for obj in objects[:]:
            obj.fall()
            if obj.off_screen():
                objects.remove(obj)
            elif basket.rect.colliderect(obj.rect):
                objects.remove(obj)
                score += 1

        # Drawing
        screen.fill(WHITE)
        basket.draw(screen)
        for obj in objects:
            obj.draw(screen)

        # Display score
        font = pygame.font.SysFont(None, 36)
        score_text = font.render(f"Score: {score}", True, BLACK)
        screen.blit(score_text, (10, 10))

        pygame.display.flip()
        clock.tick(30)

    pygame.quit()

if __name__ == "__main__":
    game_loop()
