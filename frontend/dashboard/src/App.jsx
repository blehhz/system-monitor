import { useEffect, useState } from "react";
import Section from "./components/Section";

function App() {
  const [data, setData] = useState(null);

  useEffect(() => {

    const fetchData = () => {
      fetch("http://localhost:8080/metrics")
        .then((response) => response.json())
        .then((json) => {
          setData(json);
        });
    };

    fetchData();

    const interval = setInterval(fetchData, 500);

    return () => clearInterval(interval);

  }, []);

  if (!data) {
    return <h1>Loading...</h1>;
  }

  return (
    <div>

      <h1>System Monitor</h1>

      <Section title="System">
        <p>OS: {data.system.osName}</p>

        <p>Hostname: {data.system.hostName}</p>

        <p>Kernel: {data.system.kernelVersion}</p>
      </Section>

      <Section title="CPU">
        <p>Model: {data.cpu.cpuModel}</p>

        <p>
          Usage:
          {" "}
          {data.cpu.usagePercentage.toFixed(1)}%
        </p>
      </Section>

      <Section title="Memory">
        <p>
          Usage:
          {" "}
          {data.memory.usagePercentage.toFixed(1)}%
        </p>
      </Section>

      <Section title="Disk">
        <p>
          Usage:
          {" "}
          {data.disk.usagePercentage.toFixed(1)}%
        </p>
      </Section>

    </div>
  );
}

export default App;