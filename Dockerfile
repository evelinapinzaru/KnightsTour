FROM gcc:latest
WORKDIR C:\Users\eveli\Documents\GitHub
COPY *.c *.h .
RUN gcc -o ktour *.c
CMD ["./ktour"]