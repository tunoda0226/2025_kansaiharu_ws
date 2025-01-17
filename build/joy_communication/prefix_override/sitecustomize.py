import sys
if sys.prefix == '/usr':
    sys.real_prefix = sys.prefix
    sys.prefix = sys.exec_prefix = '/home/tunotuno/2025_kansaiharu_ws/install/joy_communication'
