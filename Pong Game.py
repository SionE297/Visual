import pygame
import sys

# Initialize Pygame
pygame.init()

# Constants
WIDTH, HEIGHT = 800, 600
PADDLE_WIDTH, PADDLE_HEIGHT = 10, 100
BALL_SIZE = 15
FPS = 60
WHITE = (255, 255, 255)
BLACK = (0, 0, 0)

# Set up display
screen = pygame.display.set_mode((WIDTH, HEIGHT))
pygame.display.set_caption("Pong Game")

# Paddle class
class Paddle:
    def __init__(self, x, y):
        self.rect = pygame.Rect(x, y, PADDLE_WIDTH, PADDLE_HEIGHT)

    def move(self, dy):
        self.rect.y += dy
        # Keep paddle within bounds
        if self.rect.y < 0:
            self.rect.y = 0
        if self.rect.y > HEIGHT - PADDLE_HEIGHT:
            self.rect.y = HEIGHT - PADDLE_HEIGHT

# Ball class
class Ball:
    def __init__(self):
        self.rect = pygame.Rect(WIDTH // 2, HEIGHT // 2, BALL_SIZE, BALL_SIZE)
        self.speed_x = 5
        self.speed_y = 5

    def move(self):
        self.rect.x += self.speed_x
        self.rect.y += self.speed_y

        # Bounce off top and bottom
        if self.rect.top <= 0 or self.rect.bottom >= HEIGHT:
            self.speed_y *= -1

        # Reset if ball goes past paddle
        if self.rect.x < 0 or self.rect.x > WIDTH:
            self.reset()

    def reset(self):
        self.rect.x = WIDTH // 2
        self.rect.y = HEIGHT // 2
        self.speed_x *= -1

# Main game function
def main():
    clock = pygame.time.Clock()
    paddle_left = Paddle(30, HEIGHT // 2 - PADDLE_HEIGHT // 2)
    paddle_right = Paddle(WIDTH - 40, HEIGHT // 2 - PADDLE_HEIGHT // 2)
    ball = Ball()

    while True:
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                pygame.quit()
                sys.exit()

        # Player movement
        keys = pygame.key.get_pressed()
        if keys[pygame.K_w]:
            paddle_left.move(-5)
        if keys[pygame.K_s]:
            paddle_left.move(5)
        if keys[pygame.K_UP]:
            paddle_right.move(-5)
        if keys[pygame.K_DOWN]:
            paddle_right.move(5)

        # Move the ball
        ball.move()

        # Check for collisions
        if ball.rect.colliderect(paddle_left.rect) or ball.rect.colliderect(paddle_right.rect):
            ball.speed_x *= -1  # Bounce off paddles

        # Drawing
        screen.fill(BLACK)
        pygame.draw.rect(screen, WHITE, paddle_left.rect)
        pygame.draw.rect(screen, WHITE, paddle_right.rect)
        pygame.draw.ellipse(screen, WHITE, ball.rect)

        pygame.display.flip()
        clock.tick(FPS)

# Run the game
if __name__ == "__main__":
    main()
