FROM gcc:latest
WORKDIR /home/ktour
COPY *.c *.h .
RUN gcc -o ktour *.c -lm
CMD ["./ktour"]