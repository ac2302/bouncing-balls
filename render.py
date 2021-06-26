import os
import sys

if __name__ == '__main__':
    output_path = os.path.abspath('taf')
    if len(sys.argv) > 1:
        output_path = os.path.abspath(sys.argv[1])

    n_frames = len([item for item in os.listdir(
        os.path.join(output_path, "temp"))])

    os.system(f"mkdir {os.path.join(output_path, 'frames')}")

    for frame_no in range(n_frames):
        frame_id = f"{frame_no:06d}"
        path = os.path.join(output_path, "temp", frame_id)
        print(f"rendering frame {frame_no+1} / {n_frames}")
        os.system(
            f"cat {os.path.join(output_path, 'temp', frame_id)} | ./rf | pnmtopng > {os.path.join(output_path, 'frames', frame_id)}.png")
