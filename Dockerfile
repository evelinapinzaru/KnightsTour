FROM gcc:latest
WORKDIR C:\Users\eveli\KnightsTour\KnightsTour
COPY *.c *.h .
RUN gcc -o main *.c
CMD ["./main"]