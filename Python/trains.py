# Joel Wachsler - 2015 - Tagvaxeln

def main():
    # Minutes in a day
    mins = 1440
    
    first_input = [int(x) for x in input().split()]

    n = first_input[0]
    m = first_input[1]

    n_timer = 0
    m_timer = 0

    switches = 0

    current_switch = "n"
    current_time = 0
    

    while current_time < mins:
        if n_timer == n and m_timer != m:
            if current_switch != "n":
                switches += 1
                current_switch = "n"
            n_timer = 0
        elif m_timer == m and n_timer != n:
            if current_switch != "m":
                switches += 1
                current_switch = "m"
            m_timer = 0
        elif n_timer == n and m_timer == m:
            if current_switch == "n":
                current_switch = "m"
            else:
                current_switch = "n"
            switches += 1
            n_timer = 0
            m_timer = 0
        current_time += 1
        n_timer += 1
        m_timer += 1

    print(switches)


if __name__ == "__main__":
    main()
