FROM gcc:latest
WORKDIR C:\Users\eveli\Desktop\KnightsTour\KnightsTour
COPY main.c *.h .
RUN gcc -o main main.c
CMD ["./main"]